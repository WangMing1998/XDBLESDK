//
//  WMBLEDefine.h
//  WMBluetoothDemo
//
//  Created by Heaton on 2017/12/28.
//  Copyright © 2017年 WangMingDeveloper. All rights reserved.
//

#ifndef WMBLEDefine_h
#define WMBLEDefine_h

#define kNotificationCenter [NSNotificationCenter defaultCenter]
#define kUserDefaults [NSUserDefaults standardUserDefaults] 
#define BLE_ALERTVIEW 1
#define BLESHOW_LOG 1
#define BLECENTRALTOOLTIMEOUT 60.0
#define WM_ERROR(description) [NSError errorWithDomain:@"com.wangming.wmblelabiary" code:0 userInfo:@{NSLocalizedDescriptionKey:description}]

#define CENTRALKEY        @"CentralKey"
#define PERIPHERALKEY     @"PeripheralKey"
#define ERRORKEY          @"ErrorKey"
#define SERVICEKEY        @"ServiceKey"
#define CHARACTERISTICKEY @"CharacteristicKey"
#define RSSIKEY           @"RSSIKey"
#define LOCALNAMEKEY      @"LocalNameKey"

//蓝牙系统通知
#define BLENotificationCentralManagerDidUpdateState @"BLENotificationCentralManagerDidUpdateState"// BLE状态更新通知
#define BLENotificationDidDiscoverPeripheral @"BLENotificationDidDiscoverPeripheral"// 发现外设通知
#define BLENotificationDidConnectPeripheral @"BLENotificationDidConnectPeripheral"// 链接成功通知
#define BLENotificationDidFailToConnectPeripheral @"BLENotificationDidFailToConnectPeripheral"// 链接失败通知
#define BLENotificationDidDisconnectPeripheral @"BLENotificationDidDisconnectPeripheral"// 断开链接通知
#define BLENotificationDidDiscoverServices @"BLENotificationDidDiscoverServices"// 发现服务通知
#define BLENotificationDidDiscoverCharacteristicsForService @"BLENotificationDidDiscoverCharacteristicsForService"// 发现特征回调通知
#define BLENotificationDidUpdateValueForCharacteristic @"BLENotificationDidUpdateValueForCharacteristic"// 接收外设特征数据通知
#define BLENotificationDidWriteValueForCharacteristic @"BLENotificationDidWriteValueForCharacteristic"// 写数据到特征回调通知
#define BLENotificationDidUpdateNotificationStateForCharacteristic @"BLENotificationDidUpdateNotificationStateForCharacteristic"// 设置特征回调通知
#define BLENotificationDidReadRSSI @"BLENotificationDidReadRSSI"// RSSI信号强度变化通知
#define BLENotificationWriteDataError @"BLENotificationWriteDataError"// 写数据出错通知
#define BLENotificationWriteDataFinish @"BLENotificationWriteDataFinish"// 写数据完成通知
#define BLENotificationPeripheralDidUpdateName @"BLENotificationPeripheralDidUpdateName"// 设备名称更新通知
#define BLENotificationPeripheralServicesUpdate @"LENotificationPeripheralServicesUpdate"// 设备服务更新同知

#define WMLog(fmt, ...) if(BLESHOW_LOG) { NSLog(fmt,##__VA_ARGS__); }
#endif /* WMBLEDefine_h */
