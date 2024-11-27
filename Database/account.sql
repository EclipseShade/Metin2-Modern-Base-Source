SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `GameTime`;
CREATE TABLE `GameTime` (
  `UserID` varchar(16) NOT NULL DEFAULT '',
  `paymenttype` tinyint(2) NOT NULL DEFAULT '1',
  `LimitTime` int(11) unsigned DEFAULT '0',
  `LimitDt` datetime DEFAULT CURRENT_TIMESTAMP,
  `Scores` int(11) DEFAULT '0',
  PRIMARY KEY (`UserID`)
);

DROP TABLE IF EXISTS `GameTimeIP`;
CREATE TABLE `GameTimeIP` (
  `ipid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) DEFAULT NULL,
  `ip` varchar(15) NOT NULL DEFAULT '000.000.000.000',
  `startIP` int(11) NOT NULL DEFAULT '0',
  `endIP` int(11) NOT NULL DEFAULT '255',
  `paymenttype` tinyint(2) NOT NULL DEFAULT '1',
  `LimitTime` int(11) NOT NULL DEFAULT '0',
  `LimitDt` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `readme` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`ipid`),
  UNIQUE KEY `ip_uniq` (`ip`,`startIP`,`endIP`),
  KEY `ip_idx` (`ip`)
);

DROP TABLE IF EXISTS `GameTimeLog`;
CREATE TABLE `GameTimeLog` (
  `login` varchar(16) DEFAULT NULL,
  `type` enum('IP_FREE','FREE','IP_TIME','IP_DAY','TIME','DAY') DEFAULT NULL,
  `logon_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `logout_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `use_time` int(11) unsigned DEFAULT NULL,
  `ip` varchar(15) NOT NULL DEFAULT '000.000.000.000',
  `server` varchar(56) NOT NULL DEFAULT '',
  KEY `login_key` (`login`)
);

DROP TABLE IF EXISTS `account`;
CREATE TABLE `account` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(16) NOT NULL DEFAULT '' COMMENT 'LOGIN_MAX_LEN=30',
  `password` varchar(42) NOT NULL DEFAULT '' COMMENT 'PASSWD_MAX_LEN=16; default 45 size',
  `social_id` varchar(7) NOT NULL DEFAULT '',
  `email` varchar(100) NOT NULL DEFAULT '',
  `securitycode` varchar(192) NOT NULL DEFAULT '',
  `status` varchar(8) NOT NULL DEFAULT 'OK',
  `availDt` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `create_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_play` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `gold_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `silver_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `safebox_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `autoloot_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `fish_mind_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `marriage_fast_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `money_drop_rate_expire` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,

  `real_name` varchar(16) DEFAULT '',
  `question1` varchar(56) DEFAULT NULL,
  `answer1` varchar(56) DEFAULT NULL,
  `question2` varchar(56) DEFAULT NULL,
  `answer2` varchar(56) DEFAULT NULL,
  `cash` int(11) DEFAULT 0,
  `mileage` int(11) DEFAULT 0,
  PRIMARY KEY (`id`),
  UNIQUE KEY `login` (`login`) USING BTREE,
  KEY `social_id` (`social_id`) USING BTREE
);

DROP TABLE IF EXISTS `block_exception`;
CREATE TABLE `block_exception` (
  `login` varchar(16) NOT NULL DEFAULT ''
);

DROP TABLE IF EXISTS `iptocountry`;
CREATE TABLE `iptocountry` (
  `IP_FROM` varchar(16) DEFAULT NULL,
  `IP_TO` varchar(16) DEFAULT NULL,
  `COUNTRY_NAME` varchar(56) DEFAULT NULL
);

DROP TABLE IF EXISTS `string`;
CREATE TABLE `string` (
  `name` varchar(64) NOT NULL DEFAULT '',
  `text` text,
  PRIMARY KEY (`name`)
);

INSERT INTO `block_exception` VALUES ('NONE');
INSERT INTO `iptocountry` VALUES ('0.0.0.0', '0.0.0.0', 'NONE');
