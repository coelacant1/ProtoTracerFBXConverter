#pragma once

#include "Arduino.h"
#include "..\Math\Rotation.h"
#include "Morph.h"

class ProtoDR{
public:
    enum Morphs {
        HideSecondEye,
        HideBlush,
        TopFinOuterThin,
        TopFinInnerThin,
        MidFinTopThin,
        MidFinBotThin,
        MidFinMidBigger,
        BotFinLR1Thin,
        BotFinLR2Thin,
        BotFinLR3Thin,
        BotFinLR4Thin,
        BotFinLR5Thin,
        TopFinInnerCloseGap,
        ShockedMouth,
        HappyMouth,
        OwOMouth,
        UpsetMouth,
        SillyMouth,
        FlatMouth,
        OpenToothMouth,
        SadMouth,
        PogMouth,
        DerpyMouth,
        SkinnyEye,
        SadEye,
        CircleEye,
        HeartEye,
        ClosedEye,
        BlushEye,
        ClosedEyeBrow,
        AngryEye,
        DeadEye,
        HideEyeBrow,
        SadEyeBrow,
        AngryEyeBrow
    };

private:
    Vector3D basisVertices[128] = {Vector3D(-180.2830f,22.1568f,-65.0000f),Vector3D(-152.1540f,43.1344f,-65.0000f),Vector3D(-171.2245f,13.0983f,-65.0000f),Vector3D(-148.8166f,31.6921f,-65.0000f),Vector3D(-105.4312f,15.9589f,-65.0000f),Vector3D(-106.3847f,25.9709f,-65.0000f),Vector3D(-59.1851f,40.7506f,-65.0000f),Vector3D(-63.4760f,49.3323f,-65.0000f),Vector3D(-45.3590f,71.7402f,-65.0000f),Vector3D(-41.8793f,56.3165f,-65.0000f),Vector3D(-32.1758f,56.7576f,-65.0000f),Vector3D(-23.4279f,72.2169f,-65.0000f),Vector3D(-16.2765f,48.3788f,-65.0000f),Vector3D(-21.9976f,41.2273f,-65.0000f),Vector3D(-100.9826f,80.5753f,-65.0000f),Vector3D(-83.0233f,63.1584f,-65.0000f),Vector3D(-80.2524f,88.5146f,-65.0000f),Vector3D(-75.8719f,66.0190f,-65.0000f),Vector3D(-70.1507f,68.4028f,-65.0000f),Vector3D(-49.1731f,86.0431f,-65.0000f),Vector3D(-73.1952f,92.0431f,-65.0000f),Vector3D(-59.9632f,97.3360f,-65.0000f),Vector3D(-34.3935f,88.4269f,-65.0000f),Vector3D(-42.4984f,88.9037f,-65.0000f),Vector3D(-50.2596f,100.4235f,-65.0000f),Vector3D(-31.2936f,107.4806f,-65.0000f),Vector3D(-118.7805f,122.2771f,-65.0000f),Vector3D(-125.4552f,97.0086f,-65.0000f),Vector3D(-101.1403f,107.9742f,-65.0000f),Vector3D(-112.5826f,141.3476f,-65.0000f),Vector3D(-77.7789f,117.9862f,-65.0000f),Vector3D(-94.8077f,153.7929f,-65.0000f),Vector3D(-59.6619f,125.6144f,-65.0000f),Vector3D(-74.9183f,167.0928f,-65.0000f),Vector3D(-52.9872f,152.7899f,-65.0000f),Vector3D(-30.1026f,138.4870f,-65.0000f),Vector3D(-129.2693f,113.6953f,-65.0000f),Vector3D(-133.0834f,124.1841f,-65.0000f),Vector3D(-119.7341f,146.1152f,-65.0000f),Vector3D(-124.5017f,154.2202f,-65.0000f),Vector3D(-97.8030f,173.7675f,-65.0000f),Vector3D(-81.5930f,171.3837f,-65.0000f),Vector3D(-197.9232f,58.3908f,-65.0000f),Vector3D(-190.7718f,86.0431f,-65.0000f),Vector3D(-189.3415f,64.5887f,-65.0000f),Vector3D(-185.5274f,79.3684f,-65.0000f),Vector3D(-173.1315f,82.2290f,-65.0000f),Vector3D(-166.9336f,91.2875f,-65.0000f),Vector3D(-4.8341f,133.2426f,-65.0000f),Vector3D(-1.0200f,140.8708f,-65.0000f),Vector3D(-58.2316f,202.8501f,-65.0000f),Vector3D(-21.0441f,196.6521f,-65.0000f),Vector3D(61.9127f,246.7123f,-65.0000f),Vector3D(96.2397f,284.3766f,-65.0000f),Vector3D(-10.0785f,192.8380f,-65.0000f),Vector3D(2.7941f,147.5455f,-65.0000f),Vector3D(20.9111f,166.6161f,-65.0000f),Vector3D(21.8646f,190.9310f,-65.0000f),Vector3D(32.3534f,200.9430f,-65.0000f),Vector3D(53.3310f,230.9791f,-65.0000f),Vector3D(15.6667f,132.2891f,-65.0000f),Vector3D(74.3086f,186.6401f,-65.0000f),Vector3D(48.5633f,145.1617f,-65.0000f),Vector3D(84.7973f,172.3372f,-65.0000f),Vector3D(151.5442f,176.6281f,-65.0000f),Vector3D(186.8247f,185.2098f,-65.0000f),Vector3D(67.1571f,147.5455f,-65.0000f),Vector3D(90.0417f,165.1858f,-65.0000f),Vector3D(107.2052f,147.0688f,-65.0000f),Vector3D(134.8575f,167.0928f,-65.0000f),Vector3D(19.0040f,127.0447f,-65.0000f),Vector3D(52.8542f,139.9173f,-65.0000f),Vector3D(129.6131f,124.6609f,-65.0000f),Vector3D(114.3567f,139.4406f,-65.0000f),Vector3D(153.9280f,171.3837f,-65.0000f),Vector3D(188.2550f,180.4422f,-65.0000f),Vector3D(2.3173f,108.4509f,-65.0000f),Vector3D(12.3293f,96.5319f,-65.0000f),Vector3D(15.6667f,40.2738f,-65.0000f),Vector3D(2.3173f,13.5751f,-65.0000f),Vector3D(30.9231f,37.4132f,-65.0000f),Vector3D(48.5633f,25.9709f,-65.0000f),Vector3D(10.4223f,112.7418f,-65.0000f),Vector3D(48.0866f,110.3580f,-65.0000f),Vector3D(20.9111f,99.3924f,-65.0000f),Vector3D(35.6907f,94.6248f,-65.0000f),Vector3D(41.4119f,46.4717f,-65.0000f),Vector3D(52.3774f,35.5062f,-65.0000f),Vector3D(58.5754f,110.8348f,-65.0000f),Vector3D(70.4944f,101.7763f,-65.0000f),Vector3D(62.3895f,33.1224f,-65.0000f),Vector3D(77.6459f,56.0070f,-65.0000f),Vector3D(90.0417f,53.1464f,-65.0000f),Vector3D(102.9143f,45.9950f,-65.0000f),Vector3D(70.0177f,113.2186f,-65.0000f),Vector3D(105.2982f,110.8348f,-65.0000f),Vector3D(79.5530f,104.6368f,-65.0000f),Vector3D(93.8558f,99.3924f,-65.0000f),Vector3D(100.5305f,58.3908f,-65.0000f),Vector3D(112.4496f,50.7626f,-65.0000f),Vector3D(112.4496f,110.8348f,-65.0000f),Vector3D(124.3687f,103.2065f,-65.0000f),Vector3D(123.4152f,51.7161f,-65.0000f),Vector3D(140.5786f,75.5543f,-65.0000f),Vector3D(160.1259f,74.6008f,-65.0000f),Vector3D(177.7662f,67.4493f,-65.0000f),Vector3D(-123.8090f,93.5348f,-65.0000f),Vector3D(-109.3982f,89.0057f,-65.0000f),Vector3D(-69.8712f,104.0342f,-65.0000f),Vector3D(-71.9299f,112.6807f,-65.0000f),Vector3D(-28.9032f,131.8266f,-65.0000f),Vector3D(-33.4323f,120.0920f,-65.0000f),Vector3D(-296.1408f,194.8713f,-65.0000f),Vector3D(-295.2308f,155.7414f,-65.0000f),Vector3D(-254.2810f,154.8314f,-65.0000f),Vector3D(-255.6460f,193.9613f,-65.0000f),Vector3D(-295.2308f,208.0662f,-65.0000f),Vector3D(-295.2308f,244.0111f,-65.0000f),Vector3D(-256.5560f,244.0111f,-65.0000f),Vector3D(-257.4660f,208.0662f,-65.0000f),Vector3D(-245.1811f,242.6461f,-65.0000f),Vector3D(-244.7261f,207.1562f,-65.0000f),Vector3D(-208.3262f,242.6461f,-65.0000f),Vector3D(-208.3262f,207.6112f,-65.0000f),Vector3D(-242.9061f,192.1413f,-65.0000f),Vector3D(-241.9961f,157.5614f,-65.0000f),Vector3D(-207.4162f,156.1964f,-65.0000f),Vector3D(-206.9612f,192.5963f,-65.0000f)};
    Vector3D basisIndexes[84] = {Vector3D(2,1,0),Vector3D(3,1,2),Vector3D(3,4,1),Vector3D(4,5,1),Vector3D(4,6,5),Vector3D(6,7,5),Vector3D(9,8,7),Vector3D(9,7,6),Vector3D(9,10,8),Vector3D(10,11,8),Vector3D(10,12,11),Vector3D(10,13,12),Vector3D(14,15,16),Vector3D(15,17,16),Vector3D(18,19,20),Vector3D(19,21,20),Vector3D(24,23,22),Vector3D(22,25,24),Vector3D(26,27,28),Vector3D(28,29,26),Vector3D(28,30,29),Vector3D(30,31,29),Vector3D(30,32,31),Vector3D(32,33,31),Vector3D(32,34,33),Vector3D(32,35,34),Vector3D(38,37,36),Vector3D(38,39,37),Vector3D(38,40,39),Vector3D(38,41,40),Vector3D(44,43,42),Vector3D(44,45,43),Vector3D(45,46,43),Vector3D(46,47,43),Vector3D(48,49,50),Vector3D(49,51,50),Vector3D(50,51,52),Vector3D(52,53,50),Vector3D(54,55,56),Vector3D(57,54,56),Vector3D(58,54,57),Vector3D(54,58,59),Vector3D(62,61,60),Vector3D(63,61,62),Vector3D(63,64,61),Vector3D(64,65,61),Vector3D(68,67,66),Vector3D(68,69,67),Vector3D(72,71,70),Vector3D(72,73,71),Vector3D(72,74,73),Vector3D(72,75,74),Vector3D(78,77,76),Vector3D(76,79,78),Vector3D(79,80,78),Vector3D(79,81,80),Vector3D(84,83,82),Vector3D(84,85,83),Vector3D(86,83,85),Vector3D(86,87,83),Vector3D(90,89,88),Vector3D(90,91,89),Vector3D(90,92,91),Vector3D(90,93,92),Vector3D(96,95,94),Vector3D(96,97,95),Vector3D(97,98,95),Vector3D(95,98,99),Vector3D(102,101,100),Vector3D(102,103,101),Vector3D(102,104,103),Vector3D(102,105,104),Vector3D(106,107,108),Vector3D(108,109,106),Vector3D(108,110,109),Vector3D(108,111,110),Vector3D(112,113,114),Vector3D(114,115,112),Vector3D(118,117,116),Vector3D(116,119,118),Vector3D(120,121,122),Vector3D(121,123,122),Vector3D(124,125,126),Vector3D(126,127,124)};
    Object3D basisObj = Object3D(128, 84, basisVertices, basisIndexes);

    static const byte morphCount = 35;
    int HideSecondEyeIndexes[6] = {106,107,108,109,110,111};
    int HideBlushIndexes[12] = {14,15,16,17,18,19,20,21,22,23,24,25};
    int TopFinOuterThinIndexes[3] = {49,51,52};
    int TopFinInnerThinIndexes[3] = {56,57,58};
    int MidFinTopThinIndexes[3] = {62,63,64};
    int MidFinBotThinIndexes[3] = {71,73,74};
    int MidFinMidBiggerIndexes[4] = {66,67,68,69};
    int BotFinLR1ThinIndexes[3] = {77,78,80};
    int BotFinLR2ThinIndexes[3] = {84,85,86};
    int BotFinLR3ThinIndexes[3] = {89,91,92};
    int BotFinLR4ThinIndexes[3] = {96,97,98};
    int BotFinLR5ThinIndexes[3] = {101,103,104};
    int TopFinInnerCloseGapIndexes[3] = {54,55,59};
    int ShockedMouthIndexes[12] = {1,3,4,5,6,7,8,9,10,11,12,13};
    int HappyMouthIndexes[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int OwOMouthIndexes[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int UpsetMouthIndexes[10] = {4,5,6,7,8,9,10,11,12,13};
    int SillyMouthIndexes[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int FlatMouthIndexes[12] = {1,3,4,5,6,7,8,9,10,11,12,13};
    int OpenToothMouthIndexes[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int SadMouthIndexes[12] = {1,3,4,5,6,7,8,9,10,11,12,13};
    int PogMouthIndexes[13] = {0,1,3,4,5,6,7,8,9,10,11,12,13};
    int DerpyMouthIndexes[12] = {1,3,4,5,6,7,8,9,10,11,12,13};
    int SkinnyEyeIndexes[14] = {26,27,28,29,30,31,32,33,34,35,124,125,126,127};
    int SadEyeIndexes[5] = {26,29,31,33,34};
    int CircleEyeIndexes[9] = {26,27,28,30,31,32,33,34,35};
    int HeartEyeIndexes[10] = {26,27,28,29,30,31,32,33,34,35};
    int ClosedEyeIndexes[8] = {26,28,29,30,31,33,34,35};
    int BlushEyeIndexes[9] = {26,27,28,29,30,31,32,33,34};
    int ClosedEyeBrowIndexes[6] = {36,37,38,39,40,41};
    int AngryEyeIndexes[5] = {26,29,31,33,34};
    int DeadEyeIndexes[18] = {26,27,28,29,30,31,32,33,34,35,112,113,114,115,124,125,126,127};
    int HideEyeBrowIndexes[6] = {36,37,38,39,40,41};
    int SadEyeBrowIndexes[6] = {36,37,38,39,40,41};
    int AngryEyeBrowIndexes[6] = {36,37,38,39,40,41};

    Vector3D HideSecondEyeVectors[6] = {Vector3D(-71.8897f,149.6944f,0.0000f),Vector3D(-84.6297f,114.6595f,0.0000f),Vector3D(-105.5595f,99.6446f,0.0000f),Vector3D(-102.8296f,131.0395f,0.0172f),Vector3D(-126.0345f,111.4746f,0.0000f),Vector3D(-121.9395f,85.5396f,0.0000f)};
    Vector3D HideBlushVectors[12] = {Vector3D(-192.9192f,211.5741f,0.0000f),Vector3D(-210.2091f,190.1892f,0.0000f),Vector3D(-176.5393f,203.3842f,0.0000f),Vector3D(-181.5443f,189.2792f,0.0000f),Vector3D(-172.4443f,186.5492f,0.0000f),Vector3D(-159.6081f,171.1629f,0.0000f),Vector3D(-170.6243f,199.7442f,0.0000f),Vector3D(-149.6944f,192.9192f,0.0000f),Vector3D(-121.0295f,165.6193f,0.0000f),Vector3D(-148.3294f,166.0743f,0.0000f),Vector3D(-143.3244f,189.7342f,0.0000f),Vector3D(-125.5795f,181.5442f,0.0000f)};
    Vector3D TopFinOuterThinVectors[3] = {Vector3D(-3.1850f,-2.7300f,0.0000f),Vector3D(-16.8349f,2.7300f,0.0000f),Vector3D(14.5599f,19.1099f,0.0000f)};
    Vector3D TopFinInnerThinVectors[3] = {Vector3D(-13.1949f,-11.3750f,0.0000f),Vector3D(-20.0199f,-0.4550f,0.0000f),Vector3D(9.1000f,16.3799f,0.0000f)};
    Vector3D MidFinTopThinVectors[3] = {Vector3D(-19.1099f,-6.3700f,0.0000f),Vector3D(-7.2800f,9.5550f,0.0000f),Vector3D(19.1099f,4.5500f,0.0000f)};
    Vector3D MidFinBotThinVectors[3] = {Vector3D(-22.2949f,-8.1900f,0.0000f),Vector3D(11.8299f,-9.5550f,0.0000f),Vector3D(22.2949f,5.0050f,0.0000f)};
    Vector3D MidFinMidBiggerVectors[4] = {Vector3D(-22.7499f,-7.2800f,0.0000f),Vector3D(-8.6450f,11.3750f,0.0000f),Vector3D(11.3750f,-10.9200f,0.0000f),Vector3D(25.4799f,8.6450f,0.0000f)};
    Vector3D BotFinLR1ThinVectors[3] = {Vector3D(-6.3700f,6.3700f,0.0000f),Vector3D(-5.9150f,-17.2899f,0.0000f),Vector3D(9.5550f,-9.1000f,0.0000f)};
    Vector3D BotFinLR2ThinVectors[3] = {Vector3D(-5.8332f,8.1192f,0.0000f),Vector3D(6.8250f,9.5550f,0.0000f),Vector3D(7.2800f,-4.5500f,0.0000f)};
    Vector3D BotFinLR3ThinVectors[3] = {Vector3D(-6.8250f,5.4600f,0.0000f),Vector3D(-8.1900f,-11.8299f,0.0000f),Vector3D(7.2800f,-4.5500f,0.0000f)};
    Vector3D BotFinLR4ThinVectors[3] = {Vector3D(-5.0050f,4.5500f,0.0000f),Vector3D(6.8250f,6.3700f,0.0000f),Vector3D(8.1040f,-4.5536f,0.0000f)};
    Vector3D BotFinLR5ThinVectors[3] = {Vector3D(-7.6744f,4.7705f,0.0000f),Vector3D(-11.4078f,-15.5561f,0.0000f),Vector3D(13.2745f,-5.6002f,0.0000f)};
    Vector3D TopFinInnerCloseGapVectors[3] = {Vector3D(-15.8470f,4.6954f,0.0000f),Vector3D(-5.8693f,-4.4019f,0.0000f),Vector3D(18.7816f,26.7051f,0.0000f)};
    Vector3D ShockedMouthVectors[12] = {Vector3D(-16.7474f,1.0150f,0.0000f),Vector3D(-15.7324f,4.0600f,0.0000f),Vector3D(-25.8824f,-8.1200f,0.0000f),Vector3D(-25.8824f,-8.1200f,0.0000f),Vector3D(-57.3473f,-1.5225f,0.0000f),Vector3D(-57.3473f,-1.5225f,0.0000f),Vector3D(-40.5998f,-39.5848f,0.0000f),Vector3D(-40.5998f,-39.5848f,0.0000f),Vector3D(-34.5099f,-15.2249f,0.0000f),Vector3D(-41.1073f,-16.2399f,0.0000f),Vector3D(-29.9424f,-13.1949f,0.0000f),Vector3D(-26.3899f,-14.2099f,0.0000f)};
    Vector3D HappyMouthVectors[14] = {Vector3D(-15.2249f,15.7324f,0.0000f),Vector3D(-7.6125f,2.5375f,0.0000f),Vector3D(-15.2249f,15.7324f,0.0000f),Vector3D(-7.6125f,2.5375f,0.0000f),Vector3D(-7.1050f,0.0000f,0.0000f),Vector3D(-7.1050f,0.0000f,0.0000f),Vector3D(-23.3449f,5.0750f,0.0000f),Vector3D(-23.3449f,5.0750f,0.0000f),Vector3D(-14.2099f,-24.8674f,0.0000f),Vector3D(-14.2099f,-21.8224f,0.0000f),Vector3D(-14.7174f,-7.1050f,0.0000f),Vector3D(-24.3599f,-8.6275f,0.0000f),Vector3D(-20.2999f,29.9424f,0.0000f),Vector3D(-14.2099f,30.9574f,0.0000f)};
    Vector3D OwOMouthVectors[14] = {Vector3D(-14.7174f,14.2099f,0.0000f),Vector3D(6.0900f,-22.3299f,0.0000f),Vector3D(-14.7174f,14.2099f,0.0000f),Vector3D(6.0900f,-22.3299f,0.0000f),Vector3D(-11.6724f,31.4649f,0.0000f),Vector3D(-11.6724f,31.4649f,0.0000f),Vector3D(-13.1949f,-20.2999f,0.0000f),Vector3D(-13.1949f,-20.2999f,0.0000f),Vector3D(-7.6125f,2.5375f,0.0000f),Vector3D(-7.6125f,4.0600f,0.0000f),Vector3D(-12.6874f,7.1050f,0.0000f),Vector3D(-21.3149f,-0.5075f,0.0000f),Vector3D(-25.6102f,20.8806f,0.0000f),Vector3D(-19.5465f,24.3912f,0.0000f)};
    Vector3D UpsetMouthVectors[10] = {Vector3D(-11.8257f,6.9563f,0.0000f),Vector3D(-12.5213f,9.0432f,0.0000f),Vector3D(-41.0421f,-19.4776f,0.0000f),Vector3D(-36.8683f,-16.6951f,0.0000f),Vector3D(-38.9552f,-40.3465f,0.0000f),Vector3D(-41.7377f,-36.8683f,0.0000f),Vector3D(-32.6946f,-41.0421f,0.0000f),Vector3D(-39.6508f,-45.9115f,0.0000f),Vector3D(-24.3470f,-29.9120f,0.0000f),Vector3D(-24.3470f,-29.9120f,0.0000f)};
    Vector3D SillyMouthVectors[14] = {Vector3D(-0.6956f,2.7825f,0.0000f),Vector3D(-10.4344f,2.0869f,0.0000f),Vector3D(-0.6956f,2.7825f,0.0000f),Vector3D(-10.4344f,2.0869f,0.0000f),Vector3D(-49.3896f,18.7820f,0.0000f),Vector3D(-49.3896f,18.7820f,0.0000f),Vector3D(-77.2148f,-25.0426f,0.0000f),Vector3D(-74.4323f,-24.3470f,0.0000f),Vector3D(-85.7353f,-47.8176f,0.0000f),Vector3D(-88.3409f,-40.8692f,0.0000f),Vector3D(-76.8665f,-16.9367f,0.0000f),Vector3D(-89.4604f,-22.1480f,0.0000f),Vector3D(-85.1177f,4.7770f,0.0000f),Vector3D(-79.9064f,4.7770f,0.0000f)};
    Vector3D FlatMouthVectors[12] = {Vector3D(2.0869f,-19.4776f,0.0000f),Vector3D(0.9707f,-17.9894f,0.0000f),Vector3D(-1.3913f,-2.7825f,0.0000f),Vector3D(-1.3913f,-2.7825f,0.0000f),Vector3D(-11.8257f,-26.4339f,0.0000f),Vector3D(-14.4301f,-25.6898f,0.0000f),Vector3D(-7.7974f,-47.6422f,0.0000f),Vector3D(-8.9136f,-40.9451f,0.0000f),Vector3D(-1.2943f,-40.2980f,0.0000f),Vector3D(-4.6428f,-46.9951f,0.0000f),Vector3D(3.4781f,-22.9558f,0.0000f),Vector3D(3.4781f,-22.9558f,0.0000f)};
    Vector3D OpenToothMouthVectors[14] = {Vector3D(-10.6575f,11.6724f,0.0000f),Vector3D(-18.2699f,-7.1050f,0.0000f),Vector3D(10.5268f,-9.6720f,0.0000f),Vector3D(5.0632f,-23.9225f,0.0000f),Vector3D(-18.2057f,-3.2925f,0.0000f),Vector3D(-45.1673f,3.5525f,0.0000f),Vector3D(-49.3744f,-25.3825f,0.0000f),Vector3D(-72.0647f,-7.6125f,0.0000f),Vector3D(-68.5122f,-23.3449f,0.0000f),Vector3D(-52.2853f,-36.8848f,0.0000f),Vector3D(-48.0651f,-29.1290f,0.0000f),Vector3D(-67.4972f,-23.8524f,0.0000f),Vector3D(-58.3623f,-0.5075f,0.0000f),Vector3D(-52.6492f,0.0296f,0.0000f)};
    Vector3D SadMouthVectors[12] = {Vector3D(0.5075f,-11.1650f,0.0000f),Vector3D(0.5075f,-11.1650f,0.0000f),Vector3D(-15.2249f,8.6275f,0.0000f),Vector3D(-15.2249f,8.6275f,0.0000f),Vector3D(-42.4800f,-15.7474f,0.0000f),Vector3D(-41.1626f,-15.2068f,0.0000f),Vector3D(-40.3859f,-40.8949f,0.0000f),Vector3D(-43.9411f,-33.0826f,0.0000f),Vector3D(-41.4052f,-40.2979f,0.0000f),Vector3D(-47.8688f,-48.1648f,0.0000f),Vector3D(-50.9916f,-30.5403f,0.0000f),Vector3D(-45.0997f,-27.7536f,0.0000f)};
    Vector3D PogMouthVectors[13] = {Vector3D(-2.9690f,2.3752f,0.0000f),Vector3D(-3.5628f,3.5628f,0.0000f),Vector3D(-17.9364f,-21.9044f,0.0000f),Vector3D(-54.1295f,-9.9248f,0.0000f),Vector3D(-20.1890f,12.4697f,0.0000f),Vector3D(-93.3200f,-36.9001f,0.0000f),Vector3D(-48.0973f,10.0945f,0.0000f),Vector3D(-68.3951f,-18.8739f,0.0000f),Vector3D(-101.4822f,-52.6969f,0.0000f),Vector3D(-105.0918f,-50.8965f,0.0000f),Vector3D(-95.6587f,-36.1917f,0.0000f),Vector3D(-107.1226f,-23.3102f,0.0000f),Vector3D(-105.8784f,-25.1127f,0.0000f)};
    Vector3D DerpyMouthVectors[12] = {Vector3D(-3.7206f,-27.1606f,0.0000f),Vector3D(-5.2089f,-24.5562f,0.0000f),Vector3D(-36.8342f,-8.9295f,0.0000f),Vector3D(-36.8342f,-8.9295f,0.0000f),Vector3D(-73.2964f,-27.1606f,0.0000f),Vector3D(-73.2964f,-27.1606f,0.0000f),Vector3D(-85.5745f,-36.4622f,0.0000f),Vector3D(-85.5745f,-36.4622f,0.0000f),Vector3D(-90.7834f,-16.7428f,0.0000f),Vector3D(-106.7821f,-26.4165f,0.0000f),Vector3D(-113.4792f,7.0692f,0.0000f),Vector3D(-104.1776f,11.1619f,0.0000f)};
    Vector3D SkinnyEyeVectors[14] = {Vector3D(5.6861f,29.3845f,0.0000f),Vector3D(9.8077f,1.8751f,0.0000f),Vector3D(-5.3608f,39.6135f,0.0000f),Vector3D(31.4924f,34.3170f,0.0000f),Vector3D(-4.1514f,49.7102f,0.0000f),Vector3D(58.1696f,-13.0243f,0.0000f),Vector3D(8.8329f,18.3519f,0.0000f),Vector3D(-25.0369f,-70.0344f,0.0000f),Vector3D(-38.8831f,-43.5666f,0.0000f),Vector3D(-61.7678f,-29.2637f,0.0000f),Vector3D(146.2873f,-47.2281f,0.0000f),Vector3D(142.0408f,-60.5030f,0.0000f),Vector3D(115.5458f,-46.9731f,0.0000f),Vector3D(114.2275f,-41.0432f,0.0000f)};
    Vector3D SadEyeVectors[5] = {Vector3D(-5.1063f,-1.2766f,0.0000f),Vector3D(-2.2340f,-4.1488f,0.0000f),Vector3D(-2.8723f,-17.8720f,0.0000f),Vector3D(-0.9574f,-32.2334f,0.0000f),Vector3D(6.3828f,-14.6805f,0.0000f)};
    Vector3D CircleEyeVectors[9] = {Vector3D(3.1914f,8.2977f,0.0000f),Vector3D(10.8508f,17.8720f,0.0000f),Vector3D(-7.0211f,-3.1914f,0.0000f),Vector3D(-12.0452f,-16.5691f,0.0000f),Vector3D(-1.3993f,6.0273f,0.0000f),Vector3D(2.2340f,-11.8083f,0.0000f),Vector3D(0.9574f,-2.8723f,0.0000f),Vector3D(-1.2766f,-1.5957f,0.0000f),Vector3D(-18.5102f,-10.2125f,0.0000f)};
    Vector3D HeartEyeVectors[10] = {Vector3D(-5.2995f,25.6314f,0.0000f),Vector3D(6.8012f,33.8425f,0.0000f),Vector3D(-4.4650f,9.5780f,0.0000f),Vector3D(-0.1156f,20.3571f,0.0000f),Vector3D(-6.9726f,-8.9430f,0.0000f),Vector3D(2.7603f,1.5471f,0.0000f),Vector3D(-8.1922f,-3.3413f,0.0000f),Vector3D(2.4814f,0.4080f,0.0000f),Vector3D(-3.8981f,6.5557f,0.0000f),Vector3D(-27.0084f,2.5740f,0.0000f)};
    Vector3D ClosedEyeVectors[8] = {Vector3D(-0.3191f,-15.9571f,0.0000f),Vector3D(0.6383f,-1.9149f,0.0000f),Vector3D(9.8934f,-30.3185f,0.0000f),Vector3D(-1.8327f,-3.4842f,0.0000f),Vector3D(13.0848f,-34.1482f,0.0000f),Vector3D(13.0848f,-34.1482f,0.0000f),Vector3D(3.8297f,-7.0211f,0.0000f),Vector3D(-10.8508f,6.0637f,0.0000f)};
    Vector3D BlushEyeVectors[9] = {Vector3D(33.1908f,45.3182f,0.0000f),Vector3D(21.5888f,34.0887f,0.0000f),Vector3D(-18.5102f,-8.6168f,0.0000f),Vector3D(29.3611f,17.2337f,0.0000f),Vector3D(-32.8716f,-13.7231f,0.0000f),Vector3D(-8.6168f,-39.5736f,0.0000f),Vector3D(-20.4251f,-8.2977f,0.0000f),Vector3D(-7.6594f,-44.6799f,0.0000f),Vector3D(11.8083f,-10.8508f,0.0000f)};
    Vector3D ClosedEyeBrowVectors[6] = {Vector3D(2.5531f,6.3828f,0.0000f),Vector3D(14.3614f,10.8508f,0.0000f),Vector3D(22.6591f,-0.3191f,0.0000f),Vector3D(24.5740f,-2.2340f,0.0000f),Vector3D(19.4677f,-14.6805f,0.0000f),Vector3D(19.4677f,-14.6805f,0.0000f)};
    Vector3D AngryEyeVectors[5] = {Vector3D(6.0637f,-11.4891f,0.0000f),Vector3D(11.8083f,-16.5954f,0.0000f),Vector3D(7.3403f,-11.4891f,0.0000f),Vector3D(-0.9574f,-7.9786f,0.0000f),Vector3D(-0.9574f,-3.8297f,0.0000f)};
    Vector3D DeadEyeVectors[18] = {Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(-272.3264f,67.8655f,0.0000f),Vector3D(165.4383f,-51.5919f,0.0000f),Vector3D(241.8876f,-33.9567f,0.0000f),Vector3D(202.8282f,-26.9199f,0.0000f),Vector3D(127.1378f,-43.6784f,0.0000f),Vector3D(163.7905f,-17.2088f,0.0000f),Vector3D(132.4617f,-54.5025f,0.0000f),Vector3D(105.0800f,-56.5949f,0.0000f),Vector3D(135.9918f,-20.0213f,0.0000f)};
    Vector3D HideEyeBrowVectors[6] = {Vector3D(-165.9539f,-9.2551f,0.0000f),Vector3D(-161.4860f,20.1060f,0.0000f),Vector3D(-154.7840f,-41.1693f,0.0000f),Vector3D(-149.9968f,-10.8508f,0.0000f),Vector3D(-157.9751f,-30.5427f,0.0000f),Vector3D(-173.9325f,-66.7007f,0.0000f)};
    Vector3D SadEyeBrowVectors[6] = {Vector3D(15.3188f,30.6377f,0.0000f),Vector3D(26.4888f,27.1271f,0.0000f),Vector3D(37.0205f,-3.8297f,0.0000f),Vector3D(37.0205f,-3.8297f,0.0000f),Vector3D(52.6585f,-22.6591f,0.0000f),Vector3D(47.5522f,-24.8931f,0.0000f)};
    Vector3D AngryEyeBrowVectors[6] = {Vector3D(3.8297f,-10.8508f,0.0000f),Vector3D(9.5743f,-9.5743f,0.0000f),Vector3D(17.8720f,-7.6594f,0.0000f),Vector3D(17.8720f,-7.6594f,0.0000f),Vector3D(9.7007f,-9.1705f,0.0000f),Vector3D(3.9561f,-6.9365f,0.0000f)};

    Morph morphs[35] = {
        Morph(6, HideSecondEyeIndexes, HideSecondEyeVectors),
        Morph(12, HideBlushIndexes, HideBlushVectors),
        Morph(3, TopFinOuterThinIndexes, TopFinOuterThinVectors),
        Morph(3, TopFinInnerThinIndexes, TopFinInnerThinVectors),
        Morph(3, MidFinTopThinIndexes, MidFinTopThinVectors),
        Morph(3, MidFinBotThinIndexes, MidFinBotThinVectors),
        Morph(4, MidFinMidBiggerIndexes, MidFinMidBiggerVectors),
        Morph(3, BotFinLR1ThinIndexes, BotFinLR1ThinVectors),
        Morph(3, BotFinLR2ThinIndexes, BotFinLR2ThinVectors),
        Morph(3, BotFinLR3ThinIndexes, BotFinLR3ThinVectors),
        Morph(3, BotFinLR4ThinIndexes, BotFinLR4ThinVectors),
        Morph(3, BotFinLR5ThinIndexes, BotFinLR5ThinVectors),
        Morph(3, TopFinInnerCloseGapIndexes, TopFinInnerCloseGapVectors),
        Morph(12, ShockedMouthIndexes, ShockedMouthVectors),
        Morph(14, HappyMouthIndexes, HappyMouthVectors),
        Morph(14, OwOMouthIndexes, OwOMouthVectors),
        Morph(10, UpsetMouthIndexes, UpsetMouthVectors),
        Morph(14, SillyMouthIndexes, SillyMouthVectors),
        Morph(12, FlatMouthIndexes, FlatMouthVectors),
        Morph(14, OpenToothMouthIndexes, OpenToothMouthVectors),
        Morph(12, SadMouthIndexes, SadMouthVectors),
        Morph(13, PogMouthIndexes, PogMouthVectors),
        Morph(12, DerpyMouthIndexes, DerpyMouthVectors),
        Morph(14, SkinnyEyeIndexes, SkinnyEyeVectors),
        Morph(5, SadEyeIndexes, SadEyeVectors),
        Morph(9, CircleEyeIndexes, CircleEyeVectors),
        Morph(10, HeartEyeIndexes, HeartEyeVectors),
        Morph(8, ClosedEyeIndexes, ClosedEyeVectors),
        Morph(9, BlushEyeIndexes, BlushEyeVectors),
        Morph(6, ClosedEyeBrowIndexes, ClosedEyeBrowVectors),
        Morph(5, AngryEyeIndexes, AngryEyeVectors),
        Morph(18, DeadEyeIndexes, DeadEyeVectors),
        Morph(6, HideEyeBrowIndexes, HideEyeBrowVectors),
        Morph(6, SadEyeBrowIndexes, SadEyeBrowVectors),
        Morph(6, AngryEyeBrowIndexes, AngryEyeBrowVectors)
    };

    Quaternion offsetRotation = Rotation(EulerAngles(Vector3D(0.0000f,180.0000f,-0.0000f), EulerConstants::EulerOrderXYZR)).GetQuaternion();
    Vector3D offsetPosition = Vector3D(0.0000f,0.0000f,0.0000f);

public:
    ProtoDR(){}

    Object3D* GetObject(){
        return &basisObj;
    }

    void SetMorphWeight(Morphs morph, float weight){
        morphs[morph].Weight = weight;
    }

    float* GetMorphWeightReference(Morphs morph){
        return &morphs[morph].Weight;
    }

    void Reset(){
        for(int i = 0; i < morphCount; i++){
            morphs[i].Weight = 0.0f;
        }
    }

    void Update(){
        basisObj.ResetVertices();

        for(int i = 0; i < morphCount; i++){
            if(morphs[i].Weight > 0.0f){
                morphs[i].MorphObject3D(&basisObj);
            }
        }

        basisObj.Rotate(offsetRotation);
        basisObj.MoveRelative(offsetPosition);
    }
};
