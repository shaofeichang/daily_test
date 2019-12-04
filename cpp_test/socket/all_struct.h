#ifndef RADAR_STRUCT_H__
#define RADAR_STRUCT_H__
#pragma pack(push)
#pragma pack(1)
enum NodeID
{
    CONTROLNODE = 101,
    POSTURENODE,
    THREEDIMEN,
    DATACOLLEC,
    CONTROLSYSNODE = 201,
    TARGETRADARNODE = 301,
    FIRESYSNODEONE = 401,
    FIRESYSNODETWO,
    FIRESYSNODETHREE,
    FIRESYSNODEFOUR,
    FIRESYSNODEFIVE,
    FIRESYSNODESIX,
    SEARCHRADARNODE = 501,
    TRACKRADARNODEONE = 601,
    TRACKRADARNODETWO,
    TRACKRADARNODETHREE,
    TRACKPHOTOELECTONE = 701,
    TRACKPHOTOELECTTWO,
    TRACKPHOTOELECTTHREE
};
enum CommandType
{
    SIMUSTARTCOMMAND = 1,
    SIMUPAUSECOMMAND,
    SIMUSTOPCOMMAND,
    SIMUPLAYBACKCOMMAND,
    POSTUREREORDERCOMMAND,
    POSTUREORDERCOMMAND,
};
enum DataTypeID
{
    TARGETREALMSG = 1,
    TAGETISDESTROYMSG,
    GUNSTATUSMSG,
    MISSILESTATUSMSG,
    TARGETMIXMSG,
    TARGETDISTRIMSG,
    GUNFIREMSG,
    TARGETRADARMSG,
    SEARCHRADARMSG,
    TRACKRADARMSG,
    TRACKPHOTOELECTMSG
};
enum TargetTrueValueID
{
    FIXEDWINGAIRCRAFT1 = 3001,
    FIXEDWINGAIRCRAFT2 = 3002,
    HELICOPTERT3 = 4001,
    HELICOPTERT4 = 4002,
    HELICOPTERT5 = 4003,
    UAVT6 = 5001,
    CRUISEMISSILET7 = 6001,
    GUIDEBOMBT8 = 7001
};
typedef struct
{
    char dataType;      //1-状态数据；2-指令数据；3-仿真数据
    short nodeID;       //发送方ID定义规则见节3.3
    short sourceID;     //发送方ID号定义，注意态势装订信息下发之前和之后该ID号是不同的。
    char childDataType; //1.若数据类型为指令数据，则该项为指令类型号，其值见enumCommandType；2.若数据类型为仿真数据，则该项为数据类型ID，其值见enumDataTypeID。
    int dataLen;
    int serialNumber; //从1开始逐次加1
    double time;      //以1970年1月1日00:00:00为基准进行计算，单位为s，小数点后为ms
    char version;     //通讯接口版本号
} MessageHeader;

typedef struct
{
    short senderID;
    short reveiveID;
} SendRece;

typedef struct
{
    short PostureID;
    short SimuStep;
    short SenderIDPairNum;
    SendRece IdPair[10];
} PostureOrder;

typedef struct
{
    short targetid;
    char type;
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
    double yaw, pitch, roll;
    char interfereFlag;
    double carrierFrequency;
    double bandwidth;
    double power;
} TargetTrueValueInfoSub;
typedef struct
{
    short targetNumber;
    TargetTrueValueInfoSub targettruevalueinfo[10];
} TargetTrueValueInfo; //目标真值信息 仿真主控软件 实时型 仿真开始直至目标全部被击毁

typedef struct
{
    short targetID;
    short sourceID;
} TargetDamageVerdictInfo; //目标毁伤裁决信息 仿真主控软件 事件型	第一个目标被击毁至试验结束

typedef struct
{
    double gunAzimuth, gunHeightangle;
    char fireStatus;
    short missileLaunchedNum, missileResidualNum, shellLaunchedNum, shellResidualNum;
} ArtilleryStatusInfo; //火炮状态信息 火力模拟器	实时型	仿真开始至试验结束

typedef struct
{
    short targetNo, targetId, missileId;
    char missileStatus;
    double x, y, z;
    double vx, vy, vz;
    double yaw, pitch, roll;
} MissileDynamicInfoSub;

typedef struct
{
    MissileDynamicInfoSub missiledynamicinfo[10];
} MissileDynamicInfo; //导弹动态信息	火力模拟器	实时型	弹发射开始直到结束

typedef struct
{
    short targetNumber;
    short targetNo;
    char leadFlag;
    double x, y, z, vx, vy, vz, ax, ay, az;
    double yaw, pitch;
} TargetFusionInfo; //目标融合导引信息	火力模拟器	实时型	接收到目指或搜索雷达的目标探测数据

typedef struct
{
    short sourceID;
    char targetNumber;
    short targetID;
    short threatLevel;
} TargetAssignmentInfo; //目标分配信息	火力模拟器 指挥车	事件型	接收到目指或搜索雷达的目标探测数据

typedef struct
{
    short targetNo, targetId;
    char projectileType, totalNumber, effictiveNumber;
    double xDirDeviation, yDirDeviation, zDirDeviation;
} ArtilleryStrikeInfo; //火炮打击信息	火力模拟器	事件型	每次射击结束后发出

typedef struct
{
    short targetNo;
    double x, y, z, vx, vy, vz, yaw, pitch;
} RadarInfoSub;
typedef struct
{
    double radarAzimuth;
    double radarHeightangle;
    char radarTrackDim;
    short targetNumber;
    RadarInfoSub targetindradrinfo[10];
} TargetIndRadarInfo; //目指雷达信息	目指雷达模拟器	实时型	仿真开始至目标全部被击毁

typedef struct
{
    double radarAzimuth;
    double radarHeightangle;
    char radarTrackDim;
    short targetNumber;
    RadarInfoSub searchradarinfo[10];
} SearchRadarInfo; //搜索雷达信息	搜索雷达模拟器	实时型	仿真开始至目标全部被击毁

typedef struct
{
    double radarAzimuth;
    double radarHeightangle;
    char radarTrackDim;
    short targetNumber;
    double x, y, z, vx, vy, vz, yaw, pitch;
} TrackRadarInfo; //跟踪雷达信息	跟踪雷达模拟器	实时型	根据火力发送的目标导引信息跟踪到目标后，直至跟踪目标消失
typedef struct
{
    double photoelecAzimuth, photoelecHeightangle;
    short targetNo;
    char trackStatus;
    double detectionDistance, azimuthTrackError, heightangleTrackError;
} photoelecTrackInfo; //光电跟踪信息	光电跟踪模拟器	实时型	根据火力发送的目标导引信息跟踪到目标后，直至跟踪目标消失

typedef struct
{
    MessageHeader megHead = {1,
                             CONTROLSYSNODE,
                             CONTROLSYSNODE,
                             0,
                             sizeof(TargetAssignmentInfo),
                             1,
                             0,
                             1};
    TargetAssignmentInfo tarInfo;
} CommandCarOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             CONTROLSYSNODE,
                             CONTROLSYSNODE,
                             SIMUSTOPCOMMAND,
                             sizeof(SearchRadarInfo) + sizeof(TargetIndRadarInfo),
                             1, 0, 1};
    TargetIndRadarInfo tarRadInfo;
    SearchRadarInfo seaRadInfo;
} CommandCarInput;

typedef struct
{
    MessageHeader megHead = {2,
                             TARGETRADARNODE,
                             TARGETRADARNODE,
                             SIMUSTOPCOMMAND,
                             sizeof(TargetTrueValueInfo),
                             1, 0, 1};
    TargetTrueValueInfo tarTrueValInfo;
} TargetIndRadarInput;

typedef struct
{
    MessageHeader megHead = {1,
                             TARGETRADARNODE,
                             TARGETRADARNODE,
                             POSTUREREORDERCOMMAND,
                             sizeof(TargetIndRadarInfo),
                             1, 0, 1};
    TargetIndRadarInfo tarIndRadInfo;
} TargetIndRadarOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             TRACKRADARNODEONE,
                             TRACKRADARNODEONE,
                             POSTUREREORDERCOMMAND,
                             sizeof(TargetTrueValueInfo) + sizeof(TargetFusionInfo),
                             1, 0, 1};
    TargetTrueValueInfo tarTureValInfo;
    TargetFusionInfo tarFusInfo;
} SearchRadarInput;

typedef struct
{
    MessageHeader megHead = {1,
                             TRACKRADARNODEONE,
                             TRACKRADARNODEONE,
                             POSTUREREORDERCOMMAND,
                             sizeof(SearchRadarInfo),
                             1, 0, 1};
    SearchRadarInfo serRadInfo;
} SearchRadarOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             FIRESYSNODEONE,
                             FIRESYSNODEONE,
                             SIMUSTOPCOMMAND,
                             sizeof(TargetTrueValueInfo) + sizeof(TargetDamageVerdictInfo) +
                                 sizeof(TargetIndRadarInfo) + sizeof(SearchRadarInfo) +
                                 sizeof(TargetAssignmentInfo) + sizeof(TrackRadarInfo) +
                                 sizeof(photoelecTrackInfo),
                             1, 0, 1};
    TargetTrueValueInfo tarTruValInfo;
    TargetDamageVerdictInfo tarDamVerInfo;
    TargetIndRadarInfo tarIndRadInfo;
    SearchRadarInfo seaRadInfo;
    TargetAssignmentInfo tarAssInfo;
    TrackRadarInfo tarRadInfo;
    photoelecTrackInfo phoTraInfo;
} FireSystemInput;

typedef struct
{
    MessageHeader megHead = {1,
                             FIRESYSNODEONE,
                             FIRESYSNODEONE,
                             POSTUREREORDERCOMMAND,
                             sizeof(TargetAssignmentInfo) + sizeof(TargetFusionInfo) +
                                 sizeof(ArtilleryStatusInfo) + sizeof(MissileDynamicInfo) + 
                                 sizeof(ArtilleryStrikeInfo),
                             1, 0, 1};

    TargetAssignmentInfo tarAssInfo;
    TargetFusionInfo tarFusInfo;
    ArtilleryStatusInfo artStatusInfo;
    MissileDynamicInfo missDynInfo;
    ArtilleryStrikeInfo artStrikeInfo;
} FireSystemOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             TRACKRADARMSG,
                             TRACKRADARMSG,
                             POSTUREORDERCOMMAND,
                             sizeof(TargetTrueValueInfo) + sizeof(TargetFusionInfo) + 
                             sizeof(ArtilleryStatusInfo),
                             1, 0, 1};
    TargetTrueValueInfo tarTrueValInfo;
    TargetFusionInfo tarFusinInfo;
    ArtilleryStatusInfo artStatusInfo;
} TrackRadarInput;
typedef struct
{
    MessageHeader megHead = {1,
                             TRACKRADARMSG,
                             TRACKRADARMSG,
                             POSTUREREORDERCOMMAND,
                             sizeof(TrackRadarInfo),
                             1, 0, 1};
    TrackRadarInfo traRadInfo;
} TrackRadarOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             TRACKPHOTOELECTONE,
                             TRACKPHOTOELECTONE,
                             SIMUSTOPCOMMAND,
                             sizeof(TargetFusionInfo) + sizeof(ArtilleryStatusInfo),
                             1, 0, 1};
    TargetFusionInfo tarFusionInfo;
    ArtilleryStatusInfo artStatusInfo;
} PhotoeleInput;

typedef struct
{
    MessageHeader megHead = {1,
                             TRACKPHOTOELECTONE,
                             TRACKPHOTOELECTONE,
                             POSTUREREORDERCOMMAND,
                             sizeof(photoelecTrackInfo),
                             1, 0, 1};
    photoelecTrackInfo phoTrackInfo;

} PhotoeleOutput;

typedef struct
{
    MessageHeader megHead = {2,
                             CONTROLNODE,
                             CONTROLNODE,
                             SIMUSTOPCOMMAND,
                             sizeof(TargetAssignmentInfo) + sizeof(TargetFusionInfo) +
                                 sizeof(ArtilleryStatusInfo) + sizeof(MissileDynamicInfo) 
                                 + sizeof(ArtilleryStrikeInfo),
                             1, 0, 1};
} ControlInput;

typedef struct
{
    MessageHeader megHead = {2,
                             CONTROLNODE,
                             CONTROLNODE,
                             SIMUSTOPCOMMAND,
                             sizeof(TargetDamageVerdictInfo) + sizeof(TargetTrueValueInfo),
                             1, 0, 1};
    TargetTrueValueInfo tarTrueValInfo;
    TargetDamageVerdictInfo tarDamVerInfo;
} ControlOutput;
#pragma pack(pop)
#endif