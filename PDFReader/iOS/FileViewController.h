//
//  FileViewController.h
//  PBB
//
//  Created by Fairy on 14-5-29.
//  Copyright (c) 2014年 pyc.com.cn. All rights reserved.
//  文件查看

#import <UIKit/UIKit.h>

#import "MyOutLineViewController.h"
#import "BookmarkViewController.h"

#define FPK_REUSABLE_VIEW_NONE 0
#define FPK_REUSABLE_VIEW_SEARCH 1
#define FPK_REUSABLE_VIEW_TEXT 2
#define FPK_REUSABLE_VIEW_OUTLINE 3
#define FPK_REUSABLE_VIEW_BOOKMARK 4



static const NSInteger FPKReusableViewNone = FPK_REUSABLE_VIEW_NONE;
static const NSInteger FPKReusableViewSearch = FPK_REUSABLE_VIEW_SEARCH;
static const NSInteger FPKReusableViewText = FPK_REUSABLE_VIEW_TEXT;
static const NSInteger FPKReusableViewOutline = FPK_REUSABLE_VIEW_OUTLINE;
static const NSInteger FPKReusableViewBookmarks = FPK_REUSABLE_VIEW_BOOKMARK;

#define FPK_SEARCH_VIEW_MODE_MINI 0
#define FPK_SEARCH_VIEW_MODE_FULL 1

static const NSInteger FPKSearchViewModeMini = FPK_SEARCH_VIEW_MODE_MINI;
static const NSInteger FPKSearchViewModeFull = FPK_SEARCH_VIEW_MODE_FULL;

@interface FileViewController : UIViewController <UIPageViewControllerDelegate,
MyOutlineViewControllerDelegate,UIPopoverControllerDelegate,BookmarkViewControllerDelegate,UISearchBarDelegate>

@property (weak, nonatomic) IBOutlet UIView *pdfView;
@property (strong, nonatomic) UIPageViewController *pageViewController;

@property (nonatomic, retain) UIPopoverController * reusablePopover;

@property(nonatomic,strong) NSString *pdfDocument;



@property (weak, nonatomic) IBOutlet UIView *ibTimeView;

@property (weak, nonatomic) IBOutlet UILabel *ibTimeLabel;

@property (weak, nonatomic) IBOutlet UIButton *ibBackBtn;
@property (weak, nonatomic) IBOutlet UIButton *ibSearchBtn;
@property (weak, nonatomic) IBOutlet UIButton *ibOutLineBtn;

- (IBAction)ibaBookmarks:(UIButton *)sender;

- (IBAction)ibaOutline:(UIButton *)sender;

- (IBAction)ibSearchBtn:(id)sender;

@property (weak, nonatomic) IBOutlet UISearchBar *ibSearchBar;

@property(nonatomic,assign) CGPDFPageRef pdfPage;
@end
