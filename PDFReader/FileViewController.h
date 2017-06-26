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


@interface FileViewController : UIViewController <UIPageViewControllerDelegate,
MyOutlineViewControllerDelegate,UIPopoverControllerDelegate,BookmarkViewControllerDelegate,UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIWebView *webView;

@property (weak, nonatomic) IBOutlet UIView *pdfView;

@property (nonatomic, strong) NSString *filePath; // 文件路径
@property(nonatomic,strong) NSString *backFlage;
@property(nonatomic,strong) NSString *receviveFileId;
@property(nonatomic) NSInteger fileMakeType;  //1：自由传播 2：手动激活
@property(nonatomic,assign) NSInteger bOpenInComing;  // 跳转类型
@property(nonatomic,assign) NSInteger limitTime; // 阅读时长
@property(nonatomic,assign)int openinfoid;
@property(nonatomic,strong)NSString *waterMark;

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
