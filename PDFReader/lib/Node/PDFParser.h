//
//  PDFParser.h
//  ZoomingPDFViewer
//
//  Created by huoshuguang on 14-10-19.
//  Copyright (c) 2014年 Apple DTS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PDFReader-swift.h"
@interface PDFParser : NSObject



-(id)initWithFileName:(NSString *)filename;

-(id)initWithPDFDoc:(CGPDFDocumentRef)doc;

- (NSArray *)getPDFContents;
@end
