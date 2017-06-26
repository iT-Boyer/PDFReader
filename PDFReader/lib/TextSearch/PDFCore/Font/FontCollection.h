#import <Foundation/Foundation.h>
#import "MyFont.h"

@interface FontCollection : NSObject {
	NSMutableDictionary *fonts;
	NSArray *names;
}

/* Initialize with a font collection dictionary */
- (id)initWithFontDictionary:(CGPDFDictionaryRef)dict;

/* Return the specified font */
- (MyFont *)fontNamed:(NSString *)fontName;

@property (nonatomic, readonly) NSDictionary *fontsByName;

@property (nonatomic, readonly) NSArray *names;

@end
