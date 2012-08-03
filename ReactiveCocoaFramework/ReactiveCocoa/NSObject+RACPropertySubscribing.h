//
//  NSObject+RACPropertySubscribing.h
//  ReactiveCocoa
//
//  Created by Josh Abernathy on 3/2/12.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EXTKeyPathCoding.h"

#define RACAble(OBJECT, PROPERTY) \
	({ \
		__typeof__(OBJECT) obj = (OBJECT); \
		[obj rac_subscribableForKeyPath:@keypath(obj.PROPERTY) onObject:self]; \
	})

#define RACAbleSelf(PROPERTY) RACAble(self, PROPERTY)
#define RACAbleKeyPath(KEYPATH) [self rac_subscribableForKeyPath:KEYPATH onObject:self]

@class RACSubscribable;


@interface NSObject (RACPropertySubscribing)

// Creates a subscribable for observing on the given object the key path of the
// source object.
+ (RACSubscribable *)rac_subscribableFor:(NSObject *)object keyPath:(NSString *)keyPath onObject:(NSObject *)onObject;

// Creates a value from observing the value at the given keypath.
- (RACSubscribable *)rac_subscribableForKeyPath:(NSString *)keyPath onObject:(NSObject *)object;

@end
