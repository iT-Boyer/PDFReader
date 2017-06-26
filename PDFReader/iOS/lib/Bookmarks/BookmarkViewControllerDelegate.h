//
//  BookmarkViewControllerDelegate.h
//  FastPdfKit
//
//  Created by Gianluca Orsini on 28/02/11.
//  Copyright 2010 MobFarm S.r.l. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BookmarkViewController;

@protocol BookmarkViewControllerDelegate

-(NSUInteger)pageNum;

-(void)dismissBookmarkViewController:(BookmarkViewController *)bvc;

-(void)bookmarkViewController:(BookmarkViewController *)bvc didRequestPage:(NSUInteger)page;

-(NSString *)documentId;


////声明一个协议：利用Bookmark功能，记录历史记录
//-(void)addReadHistory;

@end
