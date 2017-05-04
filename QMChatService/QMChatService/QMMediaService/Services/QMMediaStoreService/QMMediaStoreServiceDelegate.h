//
//  QMMediaStoreServiceDelegate.h
//  QMMediaKit
//
//  Created by Vitaliy Gurkovsky on 2/7/17.
//  Copyright © 2017 quickblox. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, QMAttachmentCacheType) {

    QMAttachmentCacheTypeNone = 0,
    QMAttachmentCacheTypeMemory = 1 << 0,
    QMAttachmentCacheTypeDisc = 1 << 1
};

@class  QBChatAttachment;

NS_ASSUME_NONNULL_BEGIN
@protocol QMMediaStoreServiceDelegate <NSObject>

- (void)updateAttachment:(QBChatAttachment *)attachment
               messageID:(NSString *)messageID
                dialogID:(NSString *)dialogID;

- (void)localImageForAttachment:(QBChatAttachment *)item
                      messageID:(NSString *)messageID
                       dialogID:(NSString *)dialogID
                     completion:(void(^)(  UIImage * _Nonnull image))completion;

- (void)saveData:(NSData *)data
   forAttachment:(QBChatAttachment *)attachment
       cacheType:(QMAttachmentCacheType)cacheType
       messageID:(NSString *)messageID
        dialogID:(NSString *)dialogID;

- (BOOL)isSavedLocally:(QBChatAttachment *)attachment
             messageID:(NSString *)messageID
              dialogID:(NSString *)dialogID;

- (nullable QBChatAttachment *)cachedAttachmentWithID:(NSString *)attachmentID
                                         forMessageID:(NSString *)messageID;

@end
NS_ASSUME_NONNULL_END