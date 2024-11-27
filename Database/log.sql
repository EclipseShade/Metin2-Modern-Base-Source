SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `GameTimeLog`;
CREATE TABLE `GameTimeLog` (
  `login` varbinary(16) DEFAULT NULL,
  `type` int(11) unsigned DEFAULT NULL,
  `logon_time` datetime DEFAULT NULL,
  `logout_time` datetime DEFAULT NULL,
  `use_time` int(15) unsigned DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL,
  `server` varbinary(56) DEFAULT NULL
);

DROP TABLE IF EXISTS `acce`;
CREATE TABLE `acce` (
  `pid` int(11) NOT NULL,
  `time` timestamp NOT NULL,
  `x` int(1) NOT NULL,
  `y` int(1) NOT NULL,
  `item_vnum` int(11) NOT NULL,
  `item_uid` int(11) NOT NULL,
  `item_count` smallint(3) NOT NULL,
  `item_abs_chance` smallint(3) NOT NULL,
  `success` varbinary(3) NOT NULL
);

DROP TABLE IF EXISTS `bootlog`;
CREATE TABLE `bootlog` (
  `time` datetime DEFAULT NULL,
  `hostname` varbinary(56) DEFAULT NULL,
  `channel` int(11) DEFAULT NULL
);

DROP TABLE IF EXISTS `change_empire`;
CREATE TABLE `change_empire` (
  `account_id` int(11) unsigned NOT NULL DEFAULT '0',
  `change_count` int(11) DEFAULT NULL,
  `data` datetime DEFAULT NULL
);

DROP TABLE IF EXISTS `change_name`;
CREATE TABLE `change_name` (
  `pid` int(11) unsigned DEFAULT NULL,
  `old_name` varbinary(16) DEFAULT NULL,
  `new_name` varbinary(16) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL
);

DROP TABLE IF EXISTS `command_log`;
CREATE TABLE `command_log` (
  `userid` int(11) unsigned DEFAULT NULL,
  `server` int(11) DEFAULT 999,
  `ip` varbinary(15) DEFAULT NULL,
  `port` int(11) unsigned DEFAULT NULL,
  `username` varbinary(16) DEFAULT NULL,
  `command` varbinary(300) DEFAULT NULL,
  `date` datetime DEFAULT NULL
);

DROP TABLE IF EXISTS `cube`;
CREATE TABLE `cube` (
  `pid` int(11) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `x` int(11) unsigned DEFAULT NULL,
  `y` int(11) unsigned DEFAULT NULL,
  `item_vnum` int(11) unsigned DEFAULT NULL,
  `item_uid` int(11) unsigned DEFAULT NULL,
  `item_count` int(11) DEFAULT NULL,
  `success` int(11) DEFAULT NULL
);

DROP TABLE IF EXISTS `dragon_slay_log`;
CREATE TABLE `dragon_slay_log` (
  `guild_id` int(11) unsigned NOT NULL,
  `vnum` int(11) unsigned NOT NULL,
  `start_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `end_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
);

DROP TABLE IF EXISTS `fish_log`;
CREATE TABLE `fish_log` (
  `time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `player_id` int(10) unsigned NOT NULL DEFAULT '0',
  `map_index` tinyint(4) NOT NULL DEFAULT '0',
  `fish_id` int(10) unsigned NOT NULL DEFAULT '0',
  `fishing_level` int(11) NOT NULL DEFAULT '0',
  `waiting_time` int(11) NOT NULL DEFAULT '0',
  `success` tinyint(4) NOT NULL DEFAULT '0',
  `size` smallint(6) NOT NULL DEFAULT '0'
);

DROP TABLE IF EXISTS `goldlog`;
CREATE TABLE `goldlog` (
  `date` date DEFAULT NULL,
  `time` time DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `what` int(11) unsigned DEFAULT NULL,
  `how` varbinary(33) DEFAULT NULL COMMENT 'contains: QUEST, BUY, SELL, SHOP_BUY, SHOP_SELL, EXCHANGE_TAKE, EXCHANGE_GIVE',
  `hint` varbinary(80) DEFAULT NULL
);

DROP TABLE IF EXISTS `hack_crc_log`;
CREATE TABLE `hack_crc_log` (
  `time` datetime DEFAULT NULL,
  `login` varbinary(16) DEFAULT NULL,
  `name` varbinary(16) DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL,
  `server` varbinary(56) DEFAULT NULL,
  `why` varbinary(33) DEFAULT NULL,
  `crc` int(11) unsigned DEFAULT NULL
);

DROP TABLE IF EXISTS `hack_log`;
CREATE TABLE `hack_log` (
  `time` datetime DEFAULT NULL,
  `login` varbinary(16) DEFAULT NULL,
  `name` varbinary(16) DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL,
  `server` varbinary(56) DEFAULT NULL,
  `why` varbinary(33) DEFAULT NULL
);

DROP TABLE IF EXISTS `hackshield_log`;
CREATE TABLE `hackshield_log` (
  `time` datetime DEFAULT NULL,
  `account_id` int(11) unsigned DEFAULT NULL,
  `login` varbinary(16) DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `name` varbinary(16) DEFAULT NULL,
  `reason` int(11) unsigned DEFAULT NULL,
  `ip` int(11) unsigned DEFAULT NULL COMMENT "inet_aton('%s')"
);

DROP TABLE IF EXISTS `invalid_server_log`;
CREATE TABLE `invalid_server_log` (
  `locale_type` int(11) unsigned DEFAULT NULL,
  `log_date` datetime DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL,
  `revision` varbinary(16) DEFAULT NULL
);

DROP TABLE IF EXISTS `levellog`;
CREATE TABLE `levellog` (
  `name` varbinary(16) DEFAULT NULL,
  `level` int(11) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `account_id` int(11) unsigned DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL COMMENT 'contains REPLACE query!',
  `playtime` int(11) DEFAULT NULL
);

DROP TABLE IF EXISTS `log`;
CREATE TABLE `log` (
  `type` varbinary(20) DEFAULT NULL COMMENT 'contains: CHARACTER, ITEM',
  `time` datetime DEFAULT NULL,
  `who` int(11) unsigned DEFAULT NULL,
  `x` int(11) unsigned DEFAULT NULL,
  `y` int(11) unsigned DEFAULT NULL,
  `what` bigint(11) unsigned DEFAULT NULL,
  `how` varbinary(50) DEFAULT NULL,
  `hint` varbinary(80) DEFAULT NULL COMMENT 'snprintf with 80u size',
  `ip` varbinary(15) DEFAULT NULL,
  `vnum` int(11) unsigned DEFAULT NULL
);

DROP TABLE IF EXISTS `loginlog`;
CREATE TABLE `loginlog` (
  `type` varbinary(20) DEFAULT NULL COMMENT 'contains: LOGIN, LOGOUT',
  `time` datetime DEFAULT NULL,
  `channel` int(11) DEFAULT NULL,
  `account_id` int(11) unsigned DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `level` int(11) DEFAULT NULL,
  `job` int(11) DEFAULT NULL,
  `playtime` int(11) unsigned DEFAULT NULL
);

DROP TABLE IF EXISTS `loginlog2`;
CREATE TABLE `loginlog2` (
  `type` varbinary(20) DEFAULT NULL COMMENT 'contains: VALID, INVALID',
  `is_gm` varbinary(20) DEFAULT NULL COMMENT 'contains: Y, N',
  `login_time` datetime DEFAULT NULL,
  `channel` int(11) DEFAULT NULL,
  `account_id` int(11) unsigned DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `ip` int(11) unsigned DEFAULT NULL COMMENT "inet_aton('%s')",
  `client_version` varbinary(11) DEFAULT NULL COMMENT 'maybe 1215955205',
  `logout_time` datetime DEFAULT NULL,
  `playtime` datetime DEFAULT NULL,
  `id` int(11) DEFAULT NULL COMMENT 'maybe primary'
);

DROP TABLE IF EXISTS `money_log`;
CREATE TABLE `money_log` (
  `time` datetime DEFAULT NULL,
  `type` int(11) DEFAULT NULL,
  `vnum` int(11) DEFAULT NULL,
  `gold` int(11) DEFAULT NULL
);

DROP TABLE IF EXISTS `pcbang_loginlog`;
CREATE TABLE `pcbang_loginlog` (
  `time` datetime DEFAULT NULL,
  `pcbang_id` int(11) unsigned DEFAULT NULL,
  `ip` varbinary(15) DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `play_time` int(11) unsigned DEFAULT NULL
);

DROP TABLE IF EXISTS `quest_reward_log`;
CREATE TABLE `quest_reward_log` (
  `quest_name` varbinary(56) DEFAULT NULL,
  `pid` int(11) unsigned DEFAULT NULL,
  `level` int(11) unsigned DEFAULT NULL,
  `type` int(11) DEFAULT NULL COMMENT 'contains: EXP, ITEM',
  `how` int(11) unsigned DEFAULT NULL,
  `hint` int(11) unsigned DEFAULT NULL,
  `when` datetime DEFAULT NULL
);

DROP TABLE IF EXISTS `refinelog`;
CREATE TABLE `refinelog` (
  `pid` int(11) unsigned DEFAULT NULL,
  `item_name` varbinary(56) DEFAULT NULL,
  `item_id` int(11) unsigned DEFAULT NULL,
  `step` int(11) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `is_success` tinyint(1) DEFAULT NULL,
  `setType` varchar(20) DEFAULT NULL COMMENT 'contains: HYUNIRON, POWER, SCROLL'
);

DROP TABLE IF EXISTS `shout_log`;
CREATE TABLE `shout_log` (
  `when` datetime DEFAULT NULL,
  `where` int(11) DEFAULT NULL,
  `empire` int(11) DEFAULT NULL,
  `message` varbinary(512) DEFAULT NULL
);

DROP TABLE IF EXISTS `speed_hack`;
CREATE TABLE `speed_hack` (
  `pid` int(11) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `x` int(11) DEFAULT NULL,
  `y` int(11) DEFAULT NULL,
  `hack_count` int(11) DEFAULT NULL
);

DROP TABLE IF EXISTS `vcard_log`;
CREATE TABLE `vcard_log` (
  `vcard_id` int(11) unsigned DEFAULT NULL,
  `x` int(11) unsigned DEFAULT NULL,
  `y` int(11) unsigned DEFAULT NULL,
  `hostname` varbinary(56) DEFAULT NULL,
  `giver_name` varbinary(16) DEFAULT NULL,
  `giver_ip` varbinary(15) DEFAULT NULL,
  `taker_name` varbinary(16) DEFAULT NULL,
  `taker_ip` varbinary(15) DEFAULT NULL
);

/* NEW FEATURE: CHAT_LOG - new log table to store player/staff chat logs */
DROP TABLE IF EXISTS `chat_log`;
CREATE TABLE `chat_log` (
`where`  int unsigned NOT NULL ,
`who_id`  int unsigned NOT NULL ,
`who_name`  varchar(25) NOT NULL ,
`whom_id`  int unsigned NULL ,
`whom_name`  varchar(25) NULL ,
`type`  enum('NORMAL','WHISPER','PARTY','GUILD') NOT NULL ,
`msg`  varbinary(512) NOT NULL ,
`when`  datetime NOT NULL DEFAULT CURRENT_TIMESTAMP ,
`ip`  varchar(15) NOT NULL
);










