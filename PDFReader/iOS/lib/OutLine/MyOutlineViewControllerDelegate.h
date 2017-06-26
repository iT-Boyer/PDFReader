//
//  OutlineViewControllerDelegate.h
//  ZoomingPDFViewer
//
//  Created by huoshuguang on 14-10-19.
//  Copyright (c) 2014年 Apple DTS. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MyOutlineViewController;

@protocol MyOutlineViewControllerDelegate

-(void)dismissMyOutlineViewController:(MyOutlineViewController *)ovc;

@optional

-(void)myOutlineViewController:(MyOutlineViewController *)ovc didRequestPage:(NSUInteger)page;
-(void)myOutlineViewController:(MyOutlineViewController *)ovc didRequestPage:(NSUInteger)page file:(NSString *)file;
-(void)myOutlineViewController:(MyOutlineViewController *)ovc didRequestDestination:(NSString *)destinationName file:(NSString *)file;
@end
