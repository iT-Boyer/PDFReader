//
//  MyOutLineViewController.h
//  ZoomingPDFViewer
//
//  Created by huoshuguang on 14-10-18.
//  Copyright (c) 2014年 Apple DTS. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyOutlineViewControllerDelegate.h"

@interface MyOutLineViewController :UIViewController<UITableViewDataSource,UITableViewDelegate>

-(IBAction)actionBack:(id)sender;

@property (nonatomic, strong) NSMutableArray *outlineEntries;
@property (nonatomic, strong) NSMutableArray *openOutlineEntries;
@property (nonatomic, strong) IBOutlet UITableView *outlineTableView;
@property (assign) NSObject<MyOutlineViewControllerDelegate> *delegate;

@end
