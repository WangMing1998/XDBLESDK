//
//  WMBLETool.h
//  WMBluetoothDemo
//
//  Created by Heaton on 2017/12/29.
//  Copyright © 2017年 WangMingDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "WMBLEPeripheral.h"
#import "WMBLEDefine.h"
typedef BOOL (^WMBLEFilterPeripheralsRlueBlock)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI);
typedef void (^WMBLECentralManagerDidUpdateStateBlock)(CBCentralManager *central);
typedef void (^WMBLEDiscoverPeripheralsBlock)(CBCentralManager *central,WMBLEPeripheral *peripheral,NSDictionary *advertisementData, NSNumber *RSSI);
typedef void (^WMBLEConnectedPeripheralBlock)(CBCentralManager *central,WMBLEPeripheral *peripheral);
typedef void (^WMBLEFailToConnectBlock)(CBCentralManager *central,WMBLEPeripheral *peripheral,NSError *error);
typedef void (^WMBLEDisconnectBlock)(CBCentralManager *central,WMBLEPeripheral *peripheral,NSError *error);
typedef void (^WMBLEDiscoverServicesBlock)(WMBLEPeripheral *peripheral,CBService *service,NSError *error);
typedef void (^WMBLEDiscoverCharacteristicsBlock)(WMBLEPeripheral *peripheral,CBService *service,NSError *error);
typedef void (^WMBLEDidupdateValueForCharacteristicBlock)(WMBLEPeripheral *peripheral,CBCharacteristic *characteristic,NSError *error);
typedef void (^WMBLEDidWriteValueForCharacteristicBlock)(WMBLEPeripheral *peripheral,CBCharacteristic *characteristic,NSError *error);
typedef void (^WMBLEDidUpdateNotificationStateForCharacteristicBlock)(WMBLEPeripheral *peripheral,CBCharacteristic *characteristic,NSError *error);
typedef void (^WMBLEDidReadRSSIBlock)(WMBLEPeripheral *peripheral,NSNumber *RSSI,NSError *error);
typedef void (^WMBLEDiscoverDescriptorsForCharacteristicBlock)(WMBLEPeripheral *peripheral,CBCharacteristic *service,NSError *error);
typedef void (^WMBLEReadValueForDescriptorsBlock)(WMBLEPeripheral *peripheral,CBDescriptor *descriptor,NSError *error);

@interface WMBLETool : NSObject
@property(nonatomic,copy) WMBLEFilterPeripheralsRlueBlock            bleFiliterPeralsRuleBlock;
@property(nonatomic,copy) WMBLECentralManagerDidUpdateStateBlock     bleDidUpdateStateBlock;
@property(nonatomic,copy) WMBLEDiscoverPeripheralsBlock              bleDiscoverPeripheralsBlock;
@property(nonatomic,copy) WMBLEConnectedPeripheralBlock              bleConnectedPeripheralBlock;
@property(nonatomic,copy) WMBLEFailToConnectBlock                    bleConnectedFailPeripheralBlock;
@property(nonatomic,copy) WMBLEDisconnectBlock                       bleDisconnectedPeripheralBlock;
@property(nonatomic,copy) WMBLEDiscoverServicesBlock                 bleDiscoverServicesBlock;
@property(nonatomic,copy) WMBLEDiscoverCharacteristicsBlock          bleDiscoverCharacteristicsBlock;
@property(nonatomic,copy) WMBLEDidupdateValueForCharacteristicBlock  bleDidupdateValueForCharacteristicsBlock;
 // 向特征写入数据成功与否回调
@property(nonatomic,copy) WMBLEDidWriteValueForCharacteristicBlock   bleDidWriteValueForCharacteristicBlock;
@property(nonatomic,copy) WMBLEDidReadRSSIBlock                      bleDidReadRSSIBlock;
@property(nonatomic,copy) WMBLEDidUpdateNotificationStateForCharacteristicBlock bleDidUpdateNotificationStateForCharacteristicBlock;
@property(nonatomic,assign) CBManagerState bleState;
@property(nonatomic,strong) NSMutableArray<WMBLEPeripheral *> *connectedPeripherals;
+ (instancetype)shareInstance;
/**
 Peripherals service id, please fill nil if scanning all of the peripherals
 
 @param services services array
 @param options  Scan Settings
 
 --> options keyx
 CBCentralManagerScanOptionAllowDuplicatesKey YES/ON:Whether to repeat scanning devices have been found
 */
-(void)startScanWithServices:(NSArray<CBUUID *>*)services options:(NSDictionary *)options;

-(void)stopScanPeripherals;

/**
 Links to bluetooth peripherals
 
 @param peripheral The custom of bluetooth peripherals
 @param options  Connection Settings
 
 -->options Key
 CBConnectPeripheralOptionNotifyOnConnectionKey
 CBConnectPeripheralOptionNotifyOnDisconnectionKey
 CBConnectPeripheralOptionNotifyOnNotificationKey
 */
-(void)connectWitpPeripheral:(WMBLEPeripheral *)peripheral options:(NSDictionary *)options;

/**
 Disconnect the bluetooth device
 
 @param peripheral The custom of bluetooth peripherals
 */
-(void)disconnectWithPeripheral:(WMBLEPeripheral *)peripheral;

/**
 Disconnect all of the peripherals
 */
-(void)disconnectAllPeripheral;

-(void)autoReconnectPeripheralWithUUIDs:(NSArray<NSUUID *>*)uuids;


-(void)sendSmallData:(NSData *)data
          peripheral:(WMBLEPeripheral *)peripheral
      characteristic:(CBCharacteristic *)characteristic;
@end
