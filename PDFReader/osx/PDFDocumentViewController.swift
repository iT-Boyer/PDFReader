//
//  PDFDocumentViewController.swift
//  PDFReader
//
//  Created by pengyucheng on 18/11/2016.
//  Copyright © 2016 PBBReader. All rights reserved.
//

import Cocoa
import AppKit
import Quartz

class PDFDocumentViewController: NSViewController {

    @IBOutlet var ibPDFView:PDFView!
    
    @IBOutlet weak var ibPDFOutLineView: NSOutlineView!
    var outline:PDFOutline!
    var searchResults:NSMutableArray!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do view setup here.
//        _pdfDocument = [[NSBundle mainBundle].resourcePath stringByAppendingPathComponent:@"Manual1.pdf"];
        let path = Bundle.main.resourcePath?.appending("/Manual1.pdf")
        //必须使用fileURL
        let pdfUrl = URL.init(fileURLWithPath: path!)
        let doc = PDFDocument.init(url:pdfUrl)!
        
        //在视图上显示PDF
        ibPDFView.document = doc
        //outline即NSOutlineView数据源
        outline = ibPDFView.document?.outlineRoot
        
        //当pdfview页面发生变化，会发送更新ouline目录的通知
        NotificationCenter.default.addObserver(self,
                          selector: #selector(PDFDocumentViewController.pageChanged(_:)),
                              name: NSNotification.Name.PDFViewPageChanged,
                            object: nil)
        
        //支持搜索
        ibPDFView.document?.delegate = self as? PDFDocumentDelegate
        
    }
    
    @IBAction func takeDestinationFromOutline(_ sender: Any) {
        //TODO:未知对象
        let destination = ((sender as AnyObject).item(atRow: ibPDFOutLineView.selectedRow) as! PDFOutline).destination
        NSLog("选择目录跳转：\(String(describing: destination))")
        
        ibPDFView.go(to: destination!)
    }
    
    
    func doFind(sender:Any)
    {
        //Cancels any current searches.
        if (ibPDFView.document?.isFinding)!
        {
            ibPDFView.document?.cancelFindString()
        }
        //Allocates a mutable array to hold the search results if one does not already exist.
        if searchResults == nil
        {
            //
            searchResults = NSMutableArray.init(capacity: 10)
        }
        //Calls the PDFDocument method beginFindString:withOptions: with the desired search string.NSFindPanelCaseInsensitiveSearch
        //MARK: 开始查询包含字符串的PDF中的内容
        let textBysearh = (sender as! NSTextField).stringValue
        ibPDFView.document?.beginFindString(textBysearh, with: NSString.CompareOptions(rawValue: 0))
        
    }
    
    
    
//    override func didMatchString(_ instance: PDFSelection) {
//        //
//        // Add page label to our array.
////        [_searchResults addObject: [instance copy]];
//        searchResults.add(instance.copy())
//        
//        // Force a reload.
////        [_searchTable reloadData];
//        
//    }
    
}

//MARK: - outline代理
extension PDFDocumentViewController:NSOutlineViewDelegate,NSOutlineViewDataSource
{
    //return子目录个数
    func outlineView(_ outlineView: NSOutlineView, numberOfChildrenOfItem item: Any?) -> Int
    {
        if (item == nil)
        {
            if outline != nil {
                return outline.numberOfChildren
            }else
            {
                return 0
            }
        }else
        {
            return (item as! PDFOutline).numberOfChildren
        }
    }
    
    //return 子目录中的某个目录
    func outlineView(_ outlineView: NSOutlineView, child index: Int, ofItem item: Any?) -> Any
    {
        //
        if item == nil
        {
            if outline != nil
            {
                return outline.child(at: index)
            }
            else
            {
                return Any.self
            }
        }
        else
        {
            return (item as! PDFOutline).child(at: index)
        }
    }
    
    //MARK: return元素是否有子目录
    func outlineView(_ outlineView: NSOutlineView, isItemExpandable item: Any) -> Bool
    {
        if item == nil
        {
            //
            if outline != nil
            {
                return (outline.numberOfChildren > 0)
            }
            else
            {
                return false
            }
        }
        else
        {
            return (item as! PDFOutline).numberOfChildren > 0
        }
    }
    
    //MARK: return 每个目录的内容
    func outlineView(_ outlineView: NSOutlineView, objectValueFor tableColumn: NSTableColumn?, byItem item: Any?) -> Any?
    {
        //目录名
//        NSLog("目录名:\((item as! PDFOutline).label!)")
        return (item as! PDFOutline).label!
    }
    
    //MARK: 点击单元格的事件
    func outlineViewSelectionDidChange(_ notification: Notification)
    {
//        ibPDFOutLineView.item(atRow: i) as! PDFOutline!
        let destination = (ibPDFOutLineView.item(atRow: ibPDFOutLineView.selectedRow) as! PDFOutline).destination
//        NSLog("选择目录跳转：\(destination)")
        
        ibPDFView.go(to: destination!)
    }
    
    //MARK: Updating the outline when the page changes :NSNotification.Name.PDFViewPageChanged
    func pageChanged(_ notification:Notification)
    {
        //1. Checks to see if a root outline exists. If not, then there is no outline to update, so simply return.
        if outline == nil {
            return
        }
        /*2. Obtains the index value for the current page.
                1. The PDFView method currentPage returns the PDFPage object,
                2. the PDFDocument method indexForPage returns the actual index for that page.
                3. This index value is zero-based, so it doesn’t necessarily correspond to a page number.
            */
        var newPageIndex = (ibPDFView.document?.index(for: ibPDFView.currentPage!))!
        var newlySelectedRow = -1
        //3. Iterate through each visible element in the outline, checking to see if one of the following occurs:
        for i in 0...ibPDFOutLineView.numberOfRows {
            //
            var outlineItem:PDFOutline!
            outlineItem = ibPDFOutLineView.item(atRow: i) as! PDFOutline!
            if outlineItem == nil {
                //
                continue
            }
            //PDFOutline.destination.page获取对象，indexForPage方法：获取对象索引位置
            let destinnationPageIndex = ibPDFView.document?.index(for: (outlineItem.destination?.page)!)
            //The index of an outline element matches the index of the new page.
            if destinnationPageIndex == newPageIndex
            {
                //highlight this element (using the NSTableView method selectRow:byExtendingSelection).
                newlySelectedRow = i
                let indexSetBySelected = IndexSet.init(integer: newlySelectedRow)
                ibPDFOutLineView.selectRowIndexes(indexSetBySelected,byExtendingSelection: false)
                break
            }
            else if destinnationPageIndex! > newPageIndex
            {
                //当目录索引位置比当前页面索引大时，是因为子目录被隐藏，这时候可以高亮显示上级目录，上级目录索引为：currentrow -1
                newlySelectedRow = i - 1
                let indexSetBySelected = IndexSet.init(integer: newlySelectedRow)
                ibPDFOutLineView.selectRowIndexes(indexSetBySelected, byExtendingSelection: false)
                break
            }
        }
        if newlySelectedRow != -1 {
            //调整目录视图的焦点，让高亮的目录处于可见位置
            ibPDFOutLineView.scrollRowToVisible(newlySelectedRow)
        }
    }
    
}

