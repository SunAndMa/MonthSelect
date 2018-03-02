//
//  LFMonthPicker.h
//  LFMonthSelect
//
//  Created by sun on 2018/1/8.
//  Copyright © 2018年 sun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SJTMonth.h"

@class SJTMonthPicker;
@class SJTMonthPickerCell;

@protocol SJTMonthPickerDataSource <NSObject>
@optional

- (NSString *)monthPicker:(SJTMonthPicker *)monthPicker titleForCellMonthNameLabelInMonth:(SJTMonth *)month;

@end

@protocol SJTMonthPickerDelegate <NSObject>
@optional
- (void)monthPicker:(SJTMonthPicker *)monthPicker scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)monthPicker:(SJTMonthPicker *)monthPicker scrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)monthPicker:(SJTMonthPicker *)monthPicker scrollViewDidEndDragging:(UIScrollView *)scrollView;

- (void)monthPicker:(SJTMonthPicker *)monthPicker willSelectMonth:(SJTMonth *)month;
- (void)monthPicker:(SJTMonthPicker *)monthPicker didSelectMonth:(SJTMonth *)month;

@end

@interface SJTMonthPicker : UIView

/*
 * 激活与非激活的文字颜色设置
 */
@property (nonatomic, strong) UIColor *activeMonthNameColor;
@property (nonatomic, strong) UIColor *inactiveMonthColor;

/*
 * picker的背景颜色
 */
@property (nonatomic, strong) UIColor *backgroundPickerColor;

/* 月份显示的字体大小 */
@property (nonatomic, assign) CGFloat monthNameLabelFontSize;

/* 文字缩放的大小 */
@property (nonatomic, assign) CGFloat monthLabelZoomScale;

@property (nonatomic, readonly) CGSize monthCellSize;

/*
 * 激活的月份区间
 */
@property (nonatomic, readonly) NSRange activeMonths;

/*
 * 当前年月
 */
@property (nonatomic, assign) NSInteger month;
@property (nonatomic, assign) NSInteger year;
@property (nonatomic, assign) NSInteger currentMonth;
@property (nonatomic, strong) NSDate *currentDate;

@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;


@property (nonatomic, weak) id<SJTMonthPickerDelegate> delegate;
@property (nonatomic, weak) id<SJTMonthPickerDataSource> dataSource;

/*
 * 初始化方法
 * MZDayPicker supports storyboard
 */
- (instancetype)initWithFrame:(CGRect)frame monthCellSize:(CGSize)cellSize;
- (instancetype)initWithFrame:(CGRect)frame monthCellSize:(CGSize)cellSize month:(NSInteger)month year:(NSInteger)year;
- (instancetype)initWithFrame:(CGRect)frame month:(NSInteger)month year:(NSInteger)year;

/*
 * 设置激活的月份区间
 */
- (void)setActiveMonthsFrom:(NSInteger)fromMonth toMonth:(NSInteger)toMonth;

/*
 * 设置总的可移动区间
 */
- (void)setStartDate:(NSDate *)date endDate:(NSDate *)endDate;

/*
 * 设置当前月份
 */
- (void)setCurrentMonth:(NSInteger)currentMonth animated:(BOOL)animated;

/*
 * 设置当前日期
 */
- (void)setCurrentDate:(NSDate *)date animated:(BOOL)animated;

/*
 * 重载，刷新数据
 */
- (void)reloadData;

/*
 * Cell
 */
- (SJTMonthPickerCell *)cellForMonth:(SJTMonth *)month;

@end

@interface NSDate (Additional)
+ (NSDate *)dateFromDay:(NSInteger)day month:(NSInteger)month year:(NSInteger)year;
- (NSUInteger)numberOfDaysInMonth;
- (NSDate *)beforeMonthDate;
- (NSDate *)afterMonthDate;
- (NSString *)getYearAndMonth;
@end
