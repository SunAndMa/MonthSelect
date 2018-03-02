//
//  LFMonthPickerCell.h
//  LFMonthSelect
//
//  Created by sun on 2018/1/9.
//  Copyright © 2018年 sun. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SJTMonthPickerCell : UITableViewCell

@property (nonatomic, readonly) UIView *containerView;
@property (nonatomic, readonly) UILabel *monthNameLabel;

- (UITableViewCell *)initWithSize:(CGSize)size reuseIdentifier:(NSString *)reuseIdentifier;

@end
