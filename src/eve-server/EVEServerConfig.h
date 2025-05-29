/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2008 The EVEmu Team
    For the latest information visit http://evemu.mmoforge.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author:     Zhur, Bloody.Rabit
    Updates:    Allan
    Version:    10.3
*/

#ifndef __EVE_SERVER_CONFIG__H__INCL__
#define __EVE_SERVER_CONFIG__H__INCL__

#include "eve-server.h"
#include "utils/XMLParserEx.h"

// Add this struct at file scope so it can be referenced in the class below
struct ExploringConfig {
    uint8 maxAnomalies; // public by default in struct
    // You can add more exploring-related config settings here as needed
};

/**
 * @brief Class which parses and stores eve-server configuration.
 *
 * @author Zhur, Bloody.Rabbit
 */
class EVEServerConfig
: public XMLParserEx,
  public Singleton< EVEServerConfig >
{
public:
    EVEServerConfig();
    ~EVEServerConfig()                                  { /* do nothing here */ }

    // From <server>
    struct {
        bool TraderJoe;
        bool DisableIGB;
        bool BulkDataOD;
        bool NoobShipCheck;
        bool ModuleAutoOff;
        bool UnloadOnLinkAll;
        bool AllowNonPublished;
        bool FleetShareDelayed;
        bool BountyPayoutDelayed;
        bool LoadOldMissions;
        bool AsteroidsOnDScan;
        bool CargoMassAdditive;
        uint8 ServerSleepTime;
        uint8 MaxThreadReport;
        uint8 BountyPayoutTimer;
        uint16 idleSleepTime;
        uint16 maxPlayers;
        float processTic;
        float ModuleDamageChance;
    } server;

    // From <world>
    struct {
        bool chatLogs;
        bool globalChat;
        bool gridUnload;
        bool loginInfo;
        bool loginMsg;
        bool saveOnMove;
        bool saveOnUpdate;
        bool highSecCyno;
        bool shootRoids;
        bool shootWrecks;
        uint8 mailDelay;
        uint8 StationDockDelay;
        uint16 shipBoardDistance;
        uint16 gridUnloadTime;
        uint16 apWarptoDistance;
    } world;

    // From <rates>
    struct {
        uint8 WorldDecay;
        uint8 WebUpdate;
        uint32 TaxAmount;
        uint32 TaxedAmount;
        float npcBountyMultiply;
        float damageRate;
        float missileDamage;
        float missileTime;
        float missileRoF;
        float turretDamage;
        float turretRoF;
        float NPCDecay;
        uint8 DropItem;
        float DropMoney;
        uint8 DropSalvage;
        float RepairCost;
        float ShipRepairModifier;
        float ModuleRepairModifier;
        double secRate;
        uint32 corpCost;
        uint32 allyCost;
        uint32 medalAwardCost;
        uint32 medalCreateCost;
        float PlayerCritChance;
        float NpcCritChance;
        float SentryCritChance;
        float DroneCritChance;
        float ConcordCritChance;
    } rates;

    // from <market>
    struct {
        bool UseOrderRange;
        bool DeleteOldTransactions;
        uint8 StationOrderLimit;
        uint8 SystemOrderLimit;
        uint8 RegionOrderLimit;
        uint8 FindBuyOrder;
        uint8 FindSellOrder;
        uint8 OldPriceLimit;
        uint8 NewPriceLimit;
        uint8 HistoryUpdateTime;
        float salesTax;
    } market;

    // From <ram>
    struct {
        bool AutoEvent;
        float ProdTime;
        float CopyTime;
        float ReTime;
        float MatMod;
        float WasteMod;
        float ResPE;
        float ResME;
        float InventTime;
    } ram;

    // From <account>
    struct {
        int64 autoAccountRole;
        std::string loginMessage;
    } account;

    // From <character>
    struct {
        bool allow3edChar;
        uint8 statMultiplier;
        uint32 startCorporation;
        uint32 terminationDelay;
        uint32 startStation;
        double startBalance;
        double startAurBalance;
        double startSecRating;
    } character;

    // From <NPC>
    struct {
        bool IdleWander;
        bool UseDamageMultiplier;
        bool RoamingSpawns;
        bool StaticSpawns;
        bool TargetPod;
        uint16 WarpOut;
        uint16 RoamingTimer;
        uint16 StaticTimer;
        uint16 RespawnTimer;
        uint32 RatFaction;
        float ThreatRadius;
        float WarpFollowChance;
        float TargetPodSec;
        float DefenderMissileChance;
        float LootDropChance;
    } npc;

    // From <database>
    struct {
        bool compress;
        bool ssl;
        bool useSocket;
        bool autoReconnect;
        uint dbTimeout;
        uint8 pingTime;
        uint16 port;
        std::string host;
        std::string username;
        std::string password;
        std::string db;
    } database;

    // From <files>
    struct {
        std::string logDir;
        std::string logSettings;
        std::string cacheDir;
        std::string imageDir;
    } files;

    // From <net>
    struct {
        uint16 port;
        uint16 imageServerPort;
        std::string imageServer;
    } net;

    // From <thread>
    struct {
        uint8 NetworkThreads;
        uint8 DatabaseThreads;
        uint8 WorldThreads;
        uint8 ImageServerThreads;
        uint8 ConsoleThreads;
    } threads;

    // From <cosmic>
    struct {
        bool PIEnabled;
        bool AnomalyEnabled;
        bool DungeonEnabled;
        bool BeltEnabled;
        bool WormHoleEnabled;
        bool CiviliansEnabled;
        bool BumpEnabled;
        uint8 BeltRespawn;
        uint8 BeltGrowth;
        float roidRadiusMultiplier;
    } cosmic;

    // From exploring
    ExploringConfig exploring;

    // From <standings>
    struct {
        float MissionBonus;
        float MissionFailure;
        float MissionDeclined;
        float MissionCompleted;
        float MissionOfferExpired;
        float ImportantMissionBonus;
        float MissionFailedRollback;
        float BaseMissionMultiplier;
        float FleetMissionMultiplier;
        float Agent2CharMissionMultiplier;
        float ACorp2CharMissionMultiplier;
        float Agent2PCorpMissionMultiplier;
        float ACorp2PCorpMissionMultiplier;
        float AFaction2CharMissionMultiplier;
        float AFaction2PCorpMissionMultiplier;
    } standings;

    // From <chat>
    struct {
        bool EnableFleetChat;
        bool EnableWingChat;
        bool EnableSquadChat;
        bool EnableVoiceChat;
        bool EnforceRookieInHelp;
    } chat;

    // From <crime>
    struct {
        bool Enabled;
        uint8 CWSessionTime;
        uint8 WeaponFlagTime;
        uint16 KillRightTime;
        uint16 AggFlagTime;
        uint16 CrimFlagTime;
    } crime;

    // From <testing>
    struct {
        bool ShipHeat;
        bool EnableDrones;
    } testing;

    // From <debug>
    struct {
        bool BeanCount;
        bool StackTrace;
        bool BubbleTrack;
        bool SpawnTest;
        bool IsTestServer;
        bool UseProfiling;
        bool UseShipTracking;
        bool DeleteTrackingCans;
        bool PositionHack;
        uint16 ProfileTraceTime;
        uint32 AnomalyFaction;
    } debug;

protected:
    bool ProcessEveServer(const TiXmlElement* ele);
    bool ProcessServer(const TiXmlElement* ele);
    bool ProcessWorld(const TiXmlElement* ele);
    bool ProcessRates(const TiXmlElement* ele);
    bool ProcessMarket(const TiXmlElement* ele);
    bool ProcessAccount(const TiXmlElement* ele);
    bool ProcessCharacter(const TiXmlElement* ele);
    bool ProcessNPC(const TiXmlElement* ele);
    bool ProcessDatabase(const TiXmlElement* ele);
    bool ProcessFiles(const TiXmlElement* ele);
    bool ProcessNet(const TiXmlElement* ele);
    bool ProcessThreads(const TiXmlElement* ele);
    bool ProcessCosmic(const TiXmlElement* ele);
    bool ProcessExploring(const TiXmlElement* ele);
    bool ProcessStandings(const TiXmlElement* ele);
    bool ProcessChat(const TiXmlElement* ele);
    bool ProcessCrime(const TiXmlElement* ele);
    bool ProcessBPTimes(const TiXmlElement* ele);
    bool ProcessTesting(const TiXmlElement* ele);
    bool ProcessDebug(const TiXmlElement* ele);
};

/// A macro for easier access to the singleton.
#define sConfig \
    (EVEServerConfig::get())

#endif /* !__EVE_SERVER_CONFIG__H__INCL__ */
