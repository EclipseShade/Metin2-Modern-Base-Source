SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `affect`;
CREATE TABLE `affect` (
  `dwPID` int(10) unsigned NOT NULL DEFAULT '0',
  `bType` smallint(5) unsigned NOT NULL DEFAULT '0',
  `bApplyOn` tinyint(4) unsigned NOT NULL DEFAULT '0',
  `lApplyValue` int(11) NOT NULL DEFAULT '0',
  `dwFlag` int(10) unsigned NOT NULL DEFAULT '0',
  `lDuration` int(11) NOT NULL DEFAULT '0',
  `lSPCost` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`dwPID`,`bType`,`bApplyOn`,`lApplyValue`)
);

DROP TABLE IF EXISTS `banword`;
CREATE TABLE `banword` (
  `word` varchar(24) NOT NULL DEFAULT '',
  PRIMARY KEY (`word`)
);

DROP TABLE IF EXISTS `guild`;
CREATE TABLE `guild` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(12) NOT NULL DEFAULT '' COMMENT 'snprintf(12u)',
  `sp` smallint(6) NOT NULL DEFAULT '1000',
  `master` int(10) unsigned NOT NULL DEFAULT '0',
  `level` tinyint(2) DEFAULT NULL,
  `exp` int(11) DEFAULT NULL,
  `skill_point` tinyint(2) NOT NULL DEFAULT '0',
  `skill` tinyblob,
  `win` int(11) NOT NULL DEFAULT '0',
  `draw` int(11) NOT NULL DEFAULT '0',
  `loss` int(11) NOT NULL DEFAULT '0',
  `ladder_point` int(11) NOT NULL DEFAULT '0',
  `gold` int(11) NOT NULL DEFAULT '0',
  `token` bigint(20) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `guild_comment`;
CREATE TABLE `guild_comment` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `guild_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(24) DEFAULT NULL,
  `notice` tinyint(4) DEFAULT NULL,
  `content` varchar(50) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `aaa` (`notice`,`id`,`guild_id`),
  KEY `guild_id` (`guild_id`)
);

DROP TABLE IF EXISTS `guild_grade`;
CREATE TABLE `guild_grade` (
  `guild_id` int(11) unsigned NOT NULL DEFAULT '0',
  `grade` tinyint(4) NOT NULL DEFAULT '0',
  `name` varchar(12) NOT NULL DEFAULT '' COMMENT 'strlen(s) <= 12',
  `auth` set('ADD_MEMBER','REMOVE_MEMEBER','NOTICE','USE_SKILL') DEFAULT NULL,
  PRIMARY KEY (`guild_id`,`grade`)
);

DROP TABLE IF EXISTS `guild_member`;
CREATE TABLE `guild_member` (
  `pid` int(10) unsigned NOT NULL DEFAULT '0',
  `guild_id` int(10) unsigned NOT NULL DEFAULT '0',
  `grade` tinyint(2) DEFAULT NULL,
  `is_general` tinyint(1) NOT NULL DEFAULT '0',
  `offer` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`guild_id`,`pid`),
  UNIQUE KEY `pid` (`pid`)
);

DROP TABLE IF EXISTS `guild_war`;
CREATE TABLE `guild_war` (
  `id_from` int(11) unsigned NOT NULL DEFAULT '0',
  `id_to` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_from`,`id_to`)
);

DROP TABLE IF EXISTS `guild_war_bet`;
CREATE TABLE `guild_war_bet` (
  `login` varchar(16) NOT NULL DEFAULT '',
  `gold` int(10) unsigned NOT NULL DEFAULT '0',
  `guild` int(11) unsigned NOT NULL DEFAULT '0',
  `war_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`war_id`,`login`)
);

DROP TABLE IF EXISTS `guild_war_reservation`;
CREATE TABLE `guild_war_reservation` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guild1` int(10) unsigned NOT NULL DEFAULT '0',
  `guild2` int(10) unsigned NOT NULL DEFAULT '0',
  `time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `type` tinyint(2) unsigned NOT NULL DEFAULT '0',
  `warprice` int(10) unsigned NOT NULL DEFAULT '0',
  `initscore` int(10) unsigned NOT NULL DEFAULT '0',
  `started` tinyint(1) NOT NULL DEFAULT '0',
  `bet_from` int(10) unsigned NOT NULL DEFAULT '0',
  `bet_to` int(10) unsigned NOT NULL DEFAULT '0',
  `winner` int(11) NOT NULL DEFAULT '-1',
  `power1` int(11) NOT NULL DEFAULT '0',
  `power2` int(11) NOT NULL DEFAULT '0',
  `handicap` int(11) NOT NULL DEFAULT '0',
  `result1` int(11) NOT NULL DEFAULT '0',
  `result2` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `horse_name`;
CREATE TABLE `horse_name` (
  `id` int(11) unsigned NOT NULL DEFAULT '0',
  `name` varchar(16) NOT NULL DEFAULT 'NONAME' COMMENT 'CHARACTER_NAME_MAX_LEN+1 so 24+null',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `item`;
CREATE TABLE `item` (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `owner_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `window` enum('INVENTORY','EQUIPMENT','SAFEBOX','MALL','DRAGON_SOUL_INVENTORY','BELT_INVENTORY','GROUND') NOT NULL DEFAULT 'INVENTORY',
  `pos` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `count` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `socket0` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket1` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket2` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `attrtype0` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue0` smallint(6) NOT NULL DEFAULT 0,
  `attrtype1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue1` smallint(6) NOT NULL DEFAULT 0,
  `attrtype2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue2` smallint(6) NOT NULL DEFAULT 0,
  `attrtype3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue3` smallint(6) NOT NULL DEFAULT 0,
  `attrtype4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue4` smallint(6) NOT NULL DEFAULT 0,
  `attrtype5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue5` smallint(6) NOT NULL DEFAULT 0,
  `attrtype6` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue6` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `owner_id_idx` (`owner_id`),
  KEY `item_vnum_index` (`vnum`)
);

DROP TABLE IF EXISTS `item_attr`;
CREATE TABLE `item_attr` (
  `apply` enum('MAX_HP','MAX_SP','CON','INT','STR','DEX','ATT_SPEED','MOV_SPEED','CAST_SPEED','HP_REGEN','SP_REGEN','POISON_PCT','STUN_PCT','SLOW_PCT','CRITICAL_PCT','PENETRATE_PCT','ATTBONUS_HUMAN','ATTBONUS_ANIMAL','ATTBONUS_ORC','ATTBONUS_MILGYO','ATTBONUS_UNDEAD','ATTBONUS_DEVIL','STEAL_HP','STEAL_SP','MANA_BURN_PCT','DAMAGE_SP_RECOVER','BLOCK','DODGE','RESIST_SWORD','RESIST_TWOHAND','RESIST_DAGGER','RESIST_BELL','RESIST_FAN','RESIST_BOW','RESIST_FIRE','RESIST_ELEC','RESIST_MAGIC','RESIST_WIND','REFLECT_MELEE','REFLECT_CURSE','POISON_REDUCE','KILL_SP_RECOVER','EXP_DOUBLE_BONUS','GOLD_DOUBLE_BONUS','ITEM_DROP_BONUS','POTION_BONUS','KILL_HP_RECOVER','IMMUNE_STUN','IMMUNE_SLOW','IMMUNE_FALL','SKILL','BOW_DISTANCE','ATT_GRADE_BONUS','DEF_GRADE_BONUS','MAGIC_ATT_GRADE_BONUS','MAGIC_DEF_GRADE_BONUS','CURSE_PCT','MAX_STAMINA','ATT_BONUS_TO_WARRIOR','ATT_BONUS_TO_ASSASSIN','ATT_BONUS_TO_SURA','ATT_BONUS_TO_SHAMAN','ATT_BONUS_TO_MONSTER','ATT_BONUS','MALL_DEFBONUS','MALL_EXPBONUS','MALL_ITEMBONUS','MALL_GOLDBONUS','MAX_HP_PCT','MAX_SP_PCT','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS','SKILL_DEFEND_BONUS','NORMAL_HIT_DEFEND_BONUS','PC_BANG_EXP_BONUS','PC_BANG_DROP_BONUS','EXTRACT_HP_PCT','RESIST_WARRIOR','RESIST_ASSASSIN','RESIST_SURA','RESIST_SHAMAN','ENERGY','DEF_GRADE','COSTUME_ATTR_BONUS','MAGIC_ATT_BONUS_PER','MELEE_MAGIC_ATT_BONUS_PER','RESIST_ICE','RESIST_EARTH','RESIST_DARK','RESIST_CRITICAL','RESIST_PENETRATE','BLEEDING_REDUCE','BLEEDING_PCT','ATT_BONUS_TO_WOLFMAN','RESIST_WOLFMAN','RESIST_CLAW','ACCEDRAIN_RATE','RESIST_MAGIC_REDUCTION','ENCHANT_ELECT','ENCHANT_FIRE','ENCHANT_ICE','ENCHANT_WIND','ENCHANT_EARTH','ENCHANT_DARK','ATTBONUS_CZ','ATTBONUS_INSECT','ATTBONUS_DESERT','ATTBONUS_SWORD','ATTBONUS_TWOHAND','ATTBONUS_DAGGER','ATTBONUS_BELL','ATTBONUS_FAN','ATTBONUS_BOW','ATTBONUS_CLAW','RESIST_HUMAN','RESIST_MOUNT_FALL','UNK_117','MOUNT') NOT NULL DEFAULT 'MAX_HP',
  `prob` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv1` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv2` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv3` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv4` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv5` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `weapon` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `body` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `wrist` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `foots` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `neck` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `head` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `shield` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `ear` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_body` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_hair` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_weapon` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `pendant` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `glove` int(11) UNSIGNED NOT NULL DEFAULT 0
);

DROP TABLE IF EXISTS `item_attr_rare`;
CREATE TABLE `item_attr_rare` (
  `apply` enum('MAX_HP','MAX_SP','CON','INT','STR','DEX','ATT_SPEED','MOV_SPEED','CAST_SPEED','HP_REGEN','SP_REGEN','POISON_PCT','STUN_PCT','SLOW_PCT','CRITICAL_PCT','PENETRATE_PCT','ATTBONUS_HUMAN','ATTBONUS_ANIMAL','ATTBONUS_ORC','ATTBONUS_MILGYO','ATTBONUS_UNDEAD','ATTBONUS_DEVIL','STEAL_HP','STEAL_SP','MANA_BURN_PCT','DAMAGE_SP_RECOVER','BLOCK','DODGE','RESIST_SWORD','RESIST_TWOHAND','RESIST_DAGGER','RESIST_BELL','RESIST_FAN','RESIST_BOW','RESIST_FIRE','RESIST_ELEC','RESIST_MAGIC','RESIST_WIND','REFLECT_MELEE','REFLECT_CURSE','POISON_REDUCE','KILL_SP_RECOVER','EXP_DOUBLE_BONUS','GOLD_DOUBLE_BONUS','ITEM_DROP_BONUS','POTION_BONUS','KILL_HP_RECOVER','IMMUNE_STUN','IMMUNE_SLOW','IMMUNE_FALL','SKILL','BOW_DISTANCE','ATT_GRADE_BONUS','DEF_GRADE_BONUS','MAGIC_ATT_GRADE_BONUS','MAGIC_DEF_GRADE_BONUS','CURSE_PCT','MAX_STAMINA','ATT_BONUS_TO_WARRIOR','ATT_BONUS_TO_ASSASSIN','ATT_BONUS_TO_SURA','ATT_BONUS_TO_SHAMAN','ATT_BONUS_TO_MONSTER','ATT_BONUS','MALL_DEFBONUS','MALL_EXPBONUS','MALL_ITEMBONUS','MALL_GOLDBONUS','MAX_HP_PCT','MAX_SP_PCT','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS','SKILL_DEFEND_BONUS','NORMAL_HIT_DEFEND_BONUS','PC_BANG_EXP_BONUS','PC_BANG_DROP_BONUS','EXTRACT_HP_PCT','RESIST_WARRIOR','RESIST_ASSASSIN','RESIST_SURA','RESIST_SHAMAN','ENERGY','DEF_GRADE','COSTUME_ATTR_BONUS','MAGIC_ATT_BONUS_PER','MELEE_MAGIC_ATT_BONUS_PER','RESIST_ICE','RESIST_EARTH','RESIST_DARK','RESIST_CRITICAL','RESIST_PENETRATE','BLEEDING_REDUCE','BLEEDING_PCT','ATT_BONUS_TO_WOLFMAN','RESIST_WOLFMAN','RESIST_CLAW','ACCEDRAIN_RATE','RESIST_MAGIC_REDUCTION','ENCHANT_ELECT','ENCHANT_FIRE','ENCHANT_ICE','ENCHANT_WIND','ENCHANT_EARTH','ENCHANT_DARK','ATTBONUS_CZ','ATTBONUS_INSECT','ATTBONUS_DESERT','ATTBONUS_SWORD','ATTBONUS_TWOHAND','ATTBONUS_DAGGER','ATTBONUS_BELL','ATTBONUS_FAN','ATTBONUS_BOW','ATTBONUS_CLAW','RESIST_HUMAN','RESIST_MOUNT_FALL','UNK_117','MOUNT') NOT NULL DEFAULT 'MAX_HP',
  `prob` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv1` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv2` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv3` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv4` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `lv5` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `weapon` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `body` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `wrist` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `foots` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `neck` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `head` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `shield` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `ear` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_body` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_hair` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `costume_weapon` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `pendant` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `glove` int(11) UNSIGNED NOT NULL DEFAULT 0
);

DROP TABLE IF EXISTS `item_award`;
CREATE TABLE `item_award` (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `login` varchar(16) NOT NULL DEFAULT '' COMMENT 'LOGIN_MAX_LEN=30',
  `vnum` int(6) UNSIGNED NOT NULL DEFAULT 0,
  `count` int(10) UNSIGNED NOT NULL DEFAULT 1,
  `given_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `taken_time` datetime NULL DEFAULT NULL,
  `item_id` int(11) UNSIGNED NULL DEFAULT NULL,
  `why` varchar(128) NULL DEFAULT NULL,
  `socket0` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `socket1` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `socket2` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `attrtype0` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue0` smallint(6) NOT NULL DEFAULT 0,
  `attrtype1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue1` smallint(6) NOT NULL DEFAULT 0,
  `attrtype2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue2` smallint(6) NOT NULL DEFAULT 0,
  `attrtype3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue3` smallint(6) NOT NULL DEFAULT 0,
  `attrtype4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue4` smallint(6) NOT NULL DEFAULT 0,
  `attrtype5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue5` smallint(6) NOT NULL DEFAULT 0,
  `attrtype6` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `attrvalue6` smallint(6) NOT NULL DEFAULT 0,
  `mall` tinyint(1) NOT NULL DEFAULT 1,
  PRIMARY KEY (`id`),
  KEY `given_time_idx` (`given_time`),
  KEY `taken_time_idx` (`taken_time`)
);

DROP TABLE IF EXISTS `item_proto`;
CREATE TABLE `item_proto` (
  `vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `name` varbinary(24) NOT NULL DEFAULT 'Noname',
  `locale_name` varbinary(24) NOT NULL DEFAULT 'Noname',
  `type` tinyint(2) NOT NULL DEFAULT 0,
  `subtype` tinyint(2) NOT NULL DEFAULT 0,
  `weight` tinyint(3) NULL DEFAULT 0,
  `size` tinyint(3) UNSIGNED NULL DEFAULT 0,
  `antiflag` int(11) UNSIGNED NULL DEFAULT 0,
  `flag` int(11) UNSIGNED NULL DEFAULT 0,
  `wearflag` int(11) UNSIGNED NULL DEFAULT 0,
  `immuneflag` set('PARA','CURSE','STUN','SLEEP','SLOW','POISON','TERROR') NOT NULL DEFAULT '',
  `gold` int(11) NULL DEFAULT 0,
  `shop_buy_price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `refined_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `refine_set` smallint(11) UNSIGNED NOT NULL DEFAULT 0,
  `refine_set2` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `magic_pct` tinyint(4) NOT NULL DEFAULT 0,
  `limittype0` tinyint(4) UNSIGNED NULL DEFAULT 0,
  `limitvalue0` int(11) NULL DEFAULT 0,
  `limittype1` tinyint(4) UNSIGNED NULL DEFAULT 0,
  `limitvalue1` int(11) NULL DEFAULT 0,
  `applytype0` tinyint(4) UNSIGNED NULL DEFAULT 0,
  `applyvalue0` int(11) NULL DEFAULT 0,
  `applytype1` tinyint(4) UNSIGNED NULL DEFAULT 0,
  `applyvalue1` int(11) NULL DEFAULT 0,
  `applytype2` tinyint(4) UNSIGNED NULL DEFAULT 0,
  `applyvalue2` int(11) NULL DEFAULT 0,
  `value0` int(11) NULL DEFAULT 0,
  `value1` int(11) NULL DEFAULT 0,
  `value2` int(11) NULL DEFAULT 0,
  `value3` int(11) NULL DEFAULT 0,
  `value4` int(11) NULL DEFAULT 0,
  `value5` int(11) NULL DEFAULT 0,
  `socket0` tinyint(4) NULL DEFAULT -1,
  `socket1` tinyint(4) NULL DEFAULT -1,
  `socket2` tinyint(4) NULL DEFAULT -1,
  `socket3` tinyint(4) NULL DEFAULT -1,
  `socket4` tinyint(4) NULL DEFAULT -1,
  `socket5` tinyint(4) NULL DEFAULT -1,
  `specular` tinyint(4) NOT NULL DEFAULT 0,
  `socket_pct` tinyint(4) NOT NULL DEFAULT 0,
  `addon_type` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`)
);

DROP TABLE IF EXISTS `land`;
CREATE TABLE `land` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `map_index` int(11) unsigned NOT NULL DEFAULT '0',
  `x` int(11) unsigned NOT NULL DEFAULT '0',
  `y` int(11) unsigned NOT NULL DEFAULT '0',
  `width` int(11) unsigned NOT NULL DEFAULT '0',
  `height` int(11) unsigned NOT NULL DEFAULT '0',
  `guild_id` int(10) unsigned NOT NULL DEFAULT '0',
  `guild_level_limit` tinyint(4) unsigned NOT NULL DEFAULT '0',
  `price` int(10) unsigned NOT NULL DEFAULT '0',
  `enable` enum('YES','NO') NOT NULL DEFAULT 'NO',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `lotto_list`;
CREATE TABLE `lotto_list` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `server` varchar(56) DEFAULT NULL COMMENT "server%s=get_table_postfix(); std::string so dunno; at least 6",
  `pid` int(10) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `marriage`;
CREATE TABLE `marriage` (
  `is_married` tinyint(4) NOT NULL DEFAULT '0',
  `pid1` int(10) unsigned NOT NULL DEFAULT '0',
  `pid2` int(10) unsigned NOT NULL DEFAULT '0',
  `love_point` int(11) unsigned DEFAULT NULL,
  `time` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`pid1`,`pid2`)
);

DROP TABLE IF EXISTS `messenger_list`;
CREATE TABLE `messenger_list` (
  `account` varchar(16) NOT NULL DEFAULT '' COMMENT "24 at maximum",
  `companion` varchar(16) NOT NULL DEFAULT '' COMMENT "24 at maximum",
  PRIMARY KEY (`account`,`companion`)
);

DROP TABLE IF EXISTS `mob_proto`;
CREATE TABLE `mob_proto` (
  `vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `name` varchar(24) NOT NULL DEFAULT 'Noname',
  `locale_name` varbinary(24) NOT NULL DEFAULT 'Noname',
  `rank` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `type` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `battle_type` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `level` smallint(3) UNSIGNED NOT NULL DEFAULT 1,
  `size` enum('SMALL','MEDIUM','BIG') NOT NULL DEFAULT 'SMALL',
  `ai_flag` set('AGGR','NOMOVE','COWARD','NOATTSHINSU','NOATTCHUNJO','NOATTJINNO','ATTMOB','BERSERK','STONESKIN','GODSPEED','DEATHBLOW','REVIVE') NULL DEFAULT NULL,
  `mount_capacity` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `setRaceFlag` set('ANIMAL','UNDEAD','DEVIL','HUMAN','ORC','MILGYO','INSECT','FIRE','ICE','DESERT','TREE','ATT_ELEC','ATT_FIRE','ATT_ICE','ATT_WIND','ATT_EARTH','ATT_DARK') NOT NULL DEFAULT '',
  `setImmuneFlag` set('STUN','SLOW','FALL','CURSE','POISON','TERROR','REFLECT') NOT NULL DEFAULT '',
  `empire` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `folder` varchar(100) NOT NULL DEFAULT '',
  `on_click` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `st` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `dx` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `ht` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `iq` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `damage_min` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `damage_max` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `max_hp` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `regen_cycle` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `regen_percent` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `gold_min` int(11) NOT NULL DEFAULT 0,
  `gold_max` int(11) NOT NULL DEFAULT 0,
  `exp` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `def` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `attack_speed` smallint(6) UNSIGNED NOT NULL DEFAULT 100,
  `move_speed` smallint(6) UNSIGNED NOT NULL DEFAULT 100,
  `aggressive_hp_pct` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `aggressive_sight` smallint(10) UNSIGNED NOT NULL DEFAULT 0,
  `attack_range` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `drop_item` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `resurrection_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_curse` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_slow` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_poison` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_stun` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_critical` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_penetrate` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `resist_sword` tinyint(4) NOT NULL DEFAULT 0,
  `resist_twohand` tinyint(4) NOT NULL DEFAULT 0,
  `resist_dagger` tinyint(4) NOT NULL DEFAULT 0,
  `resist_bell` tinyint(4) NOT NULL DEFAULT 0,
  `resist_fan` tinyint(4) NOT NULL DEFAULT 0,
  `resist_bow` tinyint(4) NOT NULL DEFAULT 0,
  `resist_fire` tinyint(4) NOT NULL DEFAULT 0,
  `resist_elect` tinyint(4) NOT NULL DEFAULT 0,
  `resist_magic` tinyint(4) NOT NULL DEFAULT 0,
  `resist_wind` tinyint(4) NOT NULL DEFAULT 0,
  `resist_poison` tinyint(4) NOT NULL DEFAULT 0,
  `dam_multiply` float NULL DEFAULT NULL,
  `summon` int(11) NULL DEFAULT NULL,
  `drain_sp` int(11) NULL DEFAULT NULL,
  `mob_color` int(10) UNSIGNED NULL DEFAULT NULL,
  `polymorph_item` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `skill_level0` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum0` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level1` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum1` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level2` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum2` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level3` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum3` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level4` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum4` int(10) UNSIGNED NULL DEFAULT NULL,
  `sp_berserk` tinyint(4) NOT NULL DEFAULT 0,
  `sp_stoneskin` tinyint(4) NOT NULL DEFAULT 0,
  `sp_godspeed` tinyint(4) NOT NULL DEFAULT 0,
  `sp_deathblow` tinyint(4) NOT NULL DEFAULT 0,
  `sp_revive` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`)
);

DROP TABLE IF EXISTS `monarch`;
CREATE TABLE `monarch` (
  `empire` int(10) unsigned NOT NULL DEFAULT '0',
  `pid` int(10) unsigned DEFAULT NULL,
  `windate` datetime DEFAULT NULL,
  `money` bigint(20) unsigned DEFAULT NULL,
  PRIMARY KEY (`empire`)
);

DROP TABLE IF EXISTS `monarch_candidacy`;
CREATE TABLE `monarch_candidacy` (
  `pid` int(10) unsigned NOT NULL DEFAULT '0',
  `date` datetime DEFAULT CURRENT_TIMESTAMP,
  `name` varchar(16) DEFAULT NULL,
  `windate` datetime DEFAULT NULL,
  PRIMARY KEY (`pid`)
);

DROP TABLE IF EXISTS `monarch_election`;
CREATE TABLE `monarch_election` (
  `pid` int(10) unsigned NOT NULL DEFAULT '0',
  `selectedpid` int(10) unsigned DEFAULT '0',
  `electiondata` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`pid`)
);

DROP TABLE IF EXISTS `myshop_pricelist`;
CREATE TABLE `myshop_pricelist` (
  `owner_id` int(11) unsigned NOT NULL DEFAULT '0',
  `item_vnum` int(11) unsigned NOT NULL DEFAULT '0',
  `price` int(10) unsigned NOT NULL DEFAULT '0',
  UNIQUE KEY `list_id` (`owner_id`,`item_vnum`)
);

DROP TABLE IF EXISTS `object`;
CREATE TABLE `object` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `land_id` int(11) unsigned NOT NULL DEFAULT '0',
  `vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `map_index` int(11) unsigned NOT NULL DEFAULT '0',
  `x` int(11) NOT NULL DEFAULT '0',
  `y` int(11) NOT NULL DEFAULT '0',
  `x_rot` float NOT NULL DEFAULT '0',
  `y_rot` float NOT NULL DEFAULT '0',
  `z_rot` float NOT NULL DEFAULT '0',
  `life` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `object_proto`;
CREATE TABLE `object_proto` (
  `vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(32) NOT NULL DEFAULT '',
  `price` int(10) unsigned NOT NULL DEFAULT '0',
  `materials` varchar(64) NOT NULL DEFAULT '',
  `upgrade_vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `upgrade_limit_time` int(10) unsigned NOT NULL DEFAULT '0',
  `life` int(11) NOT NULL DEFAULT '0',
  `reg_1` int(11) NOT NULL DEFAULT '0',
  `reg_2` int(11) NOT NULL DEFAULT '0',
  `reg_3` int(11) NOT NULL DEFAULT '0',
  `reg_4` int(11) NOT NULL DEFAULT '0',
  `npc` int(10) unsigned NOT NULL DEFAULT '0',
  `group_vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `dependent_group` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`vnum`)
);

DROP TABLE IF EXISTS `pcbang_ip`;
CREATE TABLE `pcbang_ip` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `pcbang_id` int(11) NOT NULL DEFAULT '0',
  `ip` varchar(15) NOT NULL DEFAULT '000.000.000.000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `ip` (`ip`),
  KEY `pcbang_id` (`pcbang_id`)
);

DROP TABLE IF EXISTS `player`;
CREATE TABLE `player` (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `account_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `name` varchar(24) NOT NULL DEFAULT 'NONAME',
  `job` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `voice` tinyint(1) NOT NULL DEFAULT 0,
  `dir` tinyint(2) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `z` int(11) NOT NULL DEFAULT 0,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `exit_x` int(11) NOT NULL DEFAULT 0,
  `exit_y` int(11) NOT NULL DEFAULT 0,
  `exit_map_index` int(11) NOT NULL DEFAULT 0,
  `hp` int(11) NOT NULL DEFAULT 0,
  `mp` int(11) NOT NULL DEFAULT 0,
  `stamina` smallint(6) NOT NULL DEFAULT 0,
  `random_hp` smallint(5) NOT NULL DEFAULT 0 COMMENT 'if lvl 0, it will be negative',
  `random_sp` smallint(5) NOT NULL DEFAULT 0 COMMENT 'if lvl 0, it will be negative',
  `playtime` int(11) NOT NULL DEFAULT 0,
  `level` tinyint(2) UNSIGNED NOT NULL DEFAULT 1,
  `level_step` tinyint(1) NOT NULL DEFAULT 0,
  `st` smallint(3) NOT NULL DEFAULT 0,
  `ht` smallint(3) NOT NULL DEFAULT 0,
  `dx` smallint(3) NOT NULL DEFAULT 0,
  `iq` smallint(3) NOT NULL DEFAULT 0,
  `exp` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `cheque` int(11) NOT NULL DEFAULT 0,
  `stat_point` smallint(3) NOT NULL DEFAULT 0,
  `skill_point` smallint(3) NOT NULL DEFAULT 0,
  `quickslot` tinyblob NULL,
  `ip` varchar(15) NULL DEFAULT '0.0.0.0',
  `part_main` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `part_base` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `part_hair` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `part_acce` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `skill_group` tinyint(4) NOT NULL DEFAULT 0,
  `skill_level` blob NULL,
  `alignment` int(11) NOT NULL DEFAULT 0,
  `last_play` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `change_name` tinyint(1) NOT NULL DEFAULT 0,
  `mobile` varchar(24) NULL DEFAULT NULL,
  `sub_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `stat_reset_count` tinyint(4) NOT NULL DEFAULT 0,
  `horse_hp` smallint(4) NOT NULL DEFAULT 0,
  `horse_stamina` smallint(4) NOT NULL DEFAULT 0,
  `horse_level` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `horse_hp_droptime` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `horse_riding` tinyint(1) NOT NULL DEFAULT 0,
  `horse_skill_point` smallint(3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `account_id_idx` (`account_id`),
  KEY `name_idx` (`name`)
);

DROP TABLE IF EXISTS `player_deleted`;
CREATE TABLE `player_deleted` (
  `id` int(11) unsigned NOT NULL,
  `account_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `name` varchar(24) NOT NULL DEFAULT 'NONAME',
  `job` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `voice` tinyint(1) NOT NULL DEFAULT 0,
  `dir` tinyint(2) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `z` int(11) NOT NULL DEFAULT 0,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `exit_x` int(11) NOT NULL DEFAULT 0,
  `exit_y` int(11) NOT NULL DEFAULT 0,
  `exit_map_index` int(11) NOT NULL DEFAULT 0,
  `hp` int(11) NOT NULL DEFAULT 0,
  `mp` int(11) NOT NULL DEFAULT 0,
  `stamina` smallint(6) NOT NULL DEFAULT 0,
  `random_hp` smallint(5) NOT NULL DEFAULT 0 COMMENT 'if lvl 0, it will be negative',
  `random_sp` smallint(5) NOT NULL DEFAULT 0 COMMENT 'if lvl 0, it will be negative',
  `playtime` int(11) NOT NULL DEFAULT 0,
  `level` tinyint(2) UNSIGNED NOT NULL DEFAULT 1,
  `level_step` tinyint(1) NOT NULL DEFAULT 0,
  `st` smallint(3) NOT NULL DEFAULT 0,
  `ht` smallint(3) NOT NULL DEFAULT 0,
  `dx` smallint(3) NOT NULL DEFAULT 0,
  `iq` smallint(3) NOT NULL DEFAULT 0,
  `exp` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `cheque` int(11) NOT NULL DEFAULT 0,
  `stat_point` smallint(3) NOT NULL DEFAULT 0,
  `skill_point` smallint(3) NOT NULL DEFAULT 0,
  `quickslot` tinyblob NULL,
  `ip` varchar(15) NULL DEFAULT '0.0.0.0',
  `part_main` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `part_base` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `part_hair` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `part_acce` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `skill_group` tinyint(4) NOT NULL DEFAULT 0,
  `skill_level` blob NULL,
  `alignment` int(11) NOT NULL DEFAULT 0,
  `last_play` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `change_name` tinyint(1) NOT NULL DEFAULT 0,
  `mobile` varchar(24) NULL DEFAULT NULL,
  `sub_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `stat_reset_count` tinyint(4) NOT NULL DEFAULT 0,
  `horse_hp` smallint(4) NOT NULL DEFAULT 0,
  `horse_stamina` smallint(4) NOT NULL DEFAULT 0,
  `horse_level` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `horse_hp_droptime` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `horse_riding` tinyint(1) NOT NULL DEFAULT 0,
  `horse_skill_point` smallint(3) NOT NULL DEFAULT 0
);

DROP TABLE IF EXISTS `player_index`;
CREATE TABLE `player_index` (
  `id` int(11) unsigned NOT NULL DEFAULT '0',
  `pid1` int(11) unsigned NOT NULL DEFAULT '0',
  `pid2` int(11) unsigned NOT NULL DEFAULT '0',
  `pid3` int(11) unsigned NOT NULL DEFAULT '0',
  `pid4` int(11) unsigned NOT NULL DEFAULT '0',
  `pid5` int(11) unsigned NOT NULL DEFAULT '0',
  `empire` tinyint(4) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `pid1_key` (`pid1`),
  KEY `pid2_key` (`pid2`),
  KEY `pid3_key` (`pid3`),
  KEY `pid4_key` (`pid4`),
  KEY `pid5_key` (`pid5`)
);

DROP TABLE IF EXISTS `quest`;
CREATE TABLE `quest` (
  `dwPID` int(10) unsigned NOT NULL DEFAULT '0',
  `szName` varchar(32) NOT NULL DEFAULT '',
  `szState` varchar(64) NOT NULL DEFAULT '',
  `lValue` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`dwPID`,`szName`,`szState`),
  KEY `pid_idx` (`dwPID`),
  KEY `name_idx` (`szName`),
  KEY `state_idx` (`szState`)
);

DROP TABLE IF EXISTS `refine_proto`;
CREATE TABLE `refine_proto` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `vnum0` int(10) unsigned NOT NULL DEFAULT '0',
  `count0` smallint(6) NOT NULL DEFAULT '0',
  `vnum1` int(10) unsigned NOT NULL DEFAULT '0',
  `count1` smallint(6) NOT NULL DEFAULT '0',
  `vnum2` int(10) unsigned NOT NULL DEFAULT '0',
  `count2` smallint(6) NOT NULL DEFAULT '0',
  `vnum3` int(10) unsigned NOT NULL DEFAULT '0',
  `count3` smallint(6) NOT NULL DEFAULT '0',
  `vnum4` int(10) unsigned NOT NULL DEFAULT '0',
  `count4` smallint(6) NOT NULL DEFAULT '0',
  `cost` int(11) NOT NULL DEFAULT '0',
  `src_vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `result_vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `prob` smallint(6) NOT NULL DEFAULT '100',
  PRIMARY KEY (`id`)
);

DROP TABLE IF EXISTS `safebox`;
CREATE TABLE `safebox` (
  `account_id` int(10) unsigned NOT NULL DEFAULT '0',
  `size` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `password` varchar(6) NOT NULL DEFAULT '',
  `gold` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`account_id`)
);

DROP TABLE IF EXISTS `shop`;
CREATE TABLE `shop` (
  `vnum` int(11) NOT NULL DEFAULT '0',
  `name` varchar(32) NOT NULL DEFAULT 'Noname',
  `npc_vnum` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`vnum`)
);

DROP TABLE IF EXISTS `shop_item`;
CREATE TABLE `shop_item` (
  `shop_vnum` int(11) NOT NULL DEFAULT '0',
  `item_vnum` int(11) NOT NULL DEFAULT '0',
  `count` tinyint(4) unsigned NOT NULL DEFAULT '1',
  UNIQUE KEY `vnum_unique` (`shop_vnum`,`item_vnum`,`count`)
);

DROP TABLE IF EXISTS `skill_proto`;
CREATE TABLE `skill_proto` (
  `dwVnum` int(11) NOT NULL DEFAULT 0,
  `szName` varbinary(32) NOT NULL DEFAULT '',
  `bType` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelStep` tinyint(4) NOT NULL DEFAULT 0,
  `bMaxLevel` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelLimit` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `szPointOn` enum('NONE','MAX_HP','MAX_SP','HP_REGEN','SP_REGEN','BLOCK','HP','SP','ATT_GRADE','DEF_GRADE','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','BOW_DISTANCE','MOV_SPEED','ATT_SPEED','POISON_PCT','RESIST_RANGE','RESIST_MELEE','CASTING_SPEED','REFLECT_MELEE','ATT_BONUS','DEF_BONUS','RESIST_NORMAL','DODGE','KILL_HP_RECOVER','KILL_SP_RECOVER','HIT_HP_RECOVER','HIT_SP_RECOVER','CRITICAL','MANASHIELD','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS') NOT NULL DEFAULT 'NONE',
  `szPointPoly` varchar(100) NOT NULL DEFAULT '',
  `szSPCostPoly` varchar(100) NOT NULL DEFAULT '',
  `szDurationPoly` varchar(100) NOT NULL DEFAULT '',
  `szDurationSPCostPoly` varchar(100) NOT NULL DEFAULT '',
  `szCooldownPoly` varchar(100) NOT NULL DEFAULT '',
  `szMasterBonusPoly` varchar(100) NOT NULL DEFAULT '',
  `szAttackGradePoly` varchar(100) NOT NULL DEFAULT '',
  `setFlag` set('ATTACK','USE_MELEE_DAMAGE','COMPUTE_ATTGRADE','SELFONLY','USE_MAGIC_DAMAGE','USE_HP_AS_COST','COMPUTE_MAGIC_DAMAGE','SPLASH','GIVE_PENALTY','USE_ARROW_DAMAGE','PENETRATE','IGNORE_TARGET_RATING','ATTACK_SLOW','ATTACK_STUN','HP_ABSORB','SP_ABSORB','ATTACK_FIRE_CONT','REMOVE_BAD_AFFECT','REMOVE_GOOD_AFFECT','CRUSH','ATTACK_POISON','TOGGLE','DISABLE_BY_POINT_UP','CRUSH_LONG','ATTACK_WIND','ATTACK_ELEC','ATTACK_FIRE','ATTACK_BLEEDING','PARTY') NULL DEFAULT NULL,
  `setAffectFlag` enum('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','DUNGEON_UNIQUE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIND','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD','MUYEONG','REVIVE_INVISIBLE','FIRE','GICHEON','JEUNGRYEOK','TANHWAN_DASH','PABEOP','CHEONGEUN_WITH_FALL','POLYMORPH','WAR_FLAG1','WAR_FLAG2','WAR_FLAG3','CHINA_FIREWORK','HAIR','GERMANY','RAMADAN_RING','BLEEDING','RED_POSSESSION','BLUE_POSSESSION') NOT NULL DEFAULT 'YMIR',
  `szPointOn2` enum('NONE','MAX_HP','MAX_SP','HP_REGEN','SP_REGEN','BLOCK','HP','SP','ATT_GRADE','DEF_GRADE','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','BOW_DISTANCE','MOV_SPEED','ATT_SPEED','POISON_PCT','RESIST_RANGE','RESIST_MELEE','CASTING_SPEED','REFLECT_MELEE','ATT_BONUS','DEF_BONUS','RESIST_NORMAL','DODGE','KILL_HP_RECOVER','KILL_SP_RECOVER','HIT_HP_RECOVER','HIT_SP_RECOVER','CRITICAL','MANASHIELD','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS') NOT NULL DEFAULT 'NONE',
  `szPointPoly2` varchar(100) NOT NULL DEFAULT '',
  `szDurationPoly2` varchar(100) NOT NULL DEFAULT '',
  `setAffectFlag2` enum('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','DUNGEON_UNIQUE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIND','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD','MUYEONG','REVIVE_INVISIBLE','FIRE','GICHEON','JEUNGRYEOK','TANHWAN_DASH','PABEOP','CHEONGEUN_WITH_FALL','POLYMORPH','WAR_FLAG1','WAR_FLAG2','WAR_FLAG3','CHINA_FIREWORK','HAIR','GERMANY','RAMADAN_RING','BLEEDING','RED_POSSESSION','BLUE_POSSESSION') NOT NULL DEFAULT 'YMIR',
  `szPointOn3` varchar(100) NOT NULL DEFAULT 'NONE',
  `szPointPoly3` varchar(100) NOT NULL DEFAULT '',
  `szDurationPoly3` varchar(100) NOT NULL DEFAULT '',
  `szGrandMasterAddSPCostPoly` varchar(100) NOT NULL DEFAULT '',
  `prerequisiteSkillVnum` int(11) NOT NULL DEFAULT 0,
  `prerequisiteSkillLevel` int(11) NOT NULL DEFAULT 0,
  `eSkillType` enum('NORMAL','MELEE','RANGE','MAGIC') NOT NULL DEFAULT 'NORMAL',
  `iMaxHit` tinyint(4) NOT NULL DEFAULT 0,
  `szSplashAroundDamageAdjustPoly` varchar(100) NOT NULL DEFAULT '1',
  `dwTargetRange` int(11) NOT NULL DEFAULT 1000,
  `dwSplashRange` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`dwVnum`)
);

DROP TABLE IF EXISTS `sms_pool`;
CREATE TABLE `sms_pool` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `server` int(11) NOT NULL DEFAULT '0',
  `sender` varchar(32) DEFAULT NULL,
  `receiver` varchar(100) NOT NULL DEFAULT '',
  `mobile` varchar(32) DEFAULT NULL,
  `sent` enum('N','Y') NOT NULL DEFAULT 'N',
  `msg` varchar(80) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `sent_idx` (`sent`)
);

DROP TABLE IF EXISTS `string`;
CREATE TABLE `string` (
  `name` varchar(64) NOT NULL DEFAULT '',
  `text` text,
  PRIMARY KEY (`name`)
);

DROP TRIGGER IF EXISTS `MakeCharacter`;
DELIMITER ;;
CREATE TRIGGER `MakeCharacter` BEFORE INSERT ON `player` FOR EACH ROW BEGIN
	IF(new.`name` REGEXP '[^A-Za-z0-9]')THEN
		SET new.`name`=NULL;
	END IF;
END
;;
DELIMITER ;


INSERT INTO `banword` VALUES ('aryan'),('asshole'),('bastard'),('bastards'),('bitch'),('bitches'),('bitching'),('bitchy'),('boob'),('boobie'),('boobies'),('boobs'),('booby'),('boobys'),('bullshit'),('bullshitter'),('bullshitters'),('bullshitting'),('chickenshit'),('chickenshits'),('clit'),('cock'),('cockhead'),('cocks'),('cocksuck'),('cocksucker'),('cocksucking'),('cumming'),('cunt'),('cuntree'),('cuntry'),('cunts'),('dipshit'),('dipshits'),('dumbfuck'),('dumbfucks'),('dumbshit'),('dumbshits'),('fag'),('faggot'),('faggots'),('faggy'),('fags'),('fuck'),('fucka'),('fucke'),('fucked'),('fucken'),('fucker'),('fuckers'),('fuckface'),('fuckhead'),('fuckheads'),('fuckhed'),('fuckin'),('fucking'),('fucks'),('fuckup'),('fuckups'),('fukk'),('fukka'),('golem'),('goniff'),('heb'),('hebe'),('hebes'),('kike'),('kikes'),('kunt'),('kuntree'),('kuntry'),('kunts'),('motherfuck'),('motherfucken'),('motherfucker'),('motherfuckers'),('motherfuckin'),('motherfucking'),('nazi'),('nigga'),('niggah'),('niggahs'),('niggard'),('niggardly'),('niggas'),('niggaz'),('nigger'),('niggers'),('penis'),('piss'),('porn'),('porno'),('pornography'),('pussy'),('schlimazel'),('schlimiel'),('shit'),('shitface'),('shitfaced'),('shithead'),('shitheads'),('shithed'),('shits'),('shitting'),('shitty'),('slut'),('sluts'),('slutty'),('titties'),('titty'),('vagina'),('vaginal'),('whore'),('whores'),('whoring');

INSERT INTO `item_attr` VALUES ('MAX_HP', 35, 500, 500, 1000, 1500, 2000, 0, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('MAX_SP', 35, 10, 20, 30, 50, 80, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('CON', 11, 2, 4, 6, 8, 12, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('INT', 11, 2, 4, 6, 8, 12, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('STR', 11, 2, 4, 6, 8, 12, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('DEX', 11, 2, 4, 6, 8, 12, 5, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATT_SPEED', 8, 1, 2, 3, 5, 8, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('MOV_SPEED', 18, 2, 4, 6, 10, 20, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('CAST_SPEED', 8, 2, 4, 6, 10, 20, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('HP_REGEN', 60, 4, 8, 12, 20, 30, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('SP_REGEN', 60, 4, 8, 12, 20, 30, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('POISON_PCT', 8, 1, 2, 3, 5, 8, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('STUN_PCT', 18, 1, 2, 3, 5, 8, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('SLOW_PCT', 35, 1, 2, 3, 5, 8, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('CRITICAL_PCT', 18, 1, 2, 3, 5, 10, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('PENETRATE_PCT', 30, 1, 2, 3, 5, 10, 5, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_HUMAN', 20, 1, 2, 3, 5, 10, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_ANIMAL', 35, 2, 4, 6, 10, 20, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_ORC', 35, 2, 4, 6, 10, 20, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_MILGYO', 35, 2, 4, 6, 10, 20, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_UNDEAD', 35, 2, 4, 6, 10, 20, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_DEVIL', 35, 2, 4, 6, 10, 20, 5, 0, 5, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('STEAL_HP', 50, 1, 2, 3, 5, 10, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('STEAL_SP', 50, 1, 2, 3, 5, 10, 0, 5, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('MANA_BURN_PCT', 18, 1, 2, 3, 5, 10, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('BLOCK', 10, 2, 4, 6, 10, 15, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('DODGE', 10, 2, 4, 6, 10, 15, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_SWORD', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_TWOHAND', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_DAGGER', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_BELL', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_FAN', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_BOW', 18, 2, 4, 6, 10, 15, 0, 5, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('RESIST_MAGIC', 25, 2, 4, 6, 10, 15, 0, 5, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('REFLECT_MELEE', 18, 1, 2, 3, 6, 10, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('POISON_REDUCE', 18, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('EXP_DOUBLE_BONUS', 10, 2, 4, 6, 8, 20, 0, 0, 0, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('GOLD_DOUBLE_BONUS', 10, 2, 4, 6, 8, 20, 0, 0, 0, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ITEM_DROP_BONUS', 7, 2, 4, 6, 8, 20, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('IMMUNE_STUN', 5, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('IMMUNE_SLOW', 5, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATT_GRADE_BONUS', 15, 5, 10, 15, 30, 50, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_TWOHAND', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_SWORD', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_DAGGER', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_BELL', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_FAN', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_BOW', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_CLAW', 15, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('RESIST_HUMAN', 5, 2, 3, 3, 6, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_DESERT', 10, 10, 15, 15, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_INSECT', 10, 10, 15, 15, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('ATTBONUS_CZ', 10, 10, 15, 15, 20, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);
INSERT INTO `item_attr` VALUES ('RESIST_MOUNT_FALL', 10, 2, 4, 6, 10, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0);

INSERT INTO `item_attr_rare` VALUES ('MAX_HP', 1, 500, 500, 500, 500, 500, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('MAX_SP', 1, 50, 50, 50, 50, 50, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('CON', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('INT', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('STR', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('DEX', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('CRITICAL_PCT', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('PENETRATE_PCT', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_GRADE_BONUS', 1, 50, 50, 50, 50, 50, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_MONSTER', 1, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_WARRIOR', 1, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_ASSASSIN', 1, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_SURA', 1, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_SHAMAN', 1, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('RESIST_WARRIOR', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('RESIST_ASSASSIN', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('RESIST_SURA', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('RESIST_SHAMAN', 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('ATT_SPEED', 1, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);
INSERT INTO `item_attr_rare` VALUES ('MOV_SPEED', 1, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0);

INSERT INTO `land` VALUES ('1', '1', '20200', '10000', '3000', '3000', '0', '10', '65000000', 'YES'),('2', '1', '23500', '13600', '3000', '3000', '0', '10', '65000000', 'YES'),('3', '1', '27600', '10900', '3000', '3000', '0', '10', '65000000', 'YES'),('4', '1', '55600', '9600', '3000', '3000', '0', '10', '65000000', 'YES'),('5', '1', '57100', '3800', '3000', '3000', '0', '10', '65000000', 'YES'),('6', '1', '60900', '5200', '3000', '3000', '0', '10', '65000000', 'YES'),('7', '1', '66100', '7900', '3000', '3000', '0', '10', '65000000', 'YES'),('8', '1', '81400', '16800', '3000', '3000', '0', '10', '65000000', 'YES'),('9', '1', '90700', '20400', '3000', '3000', '0', '10', '50000000', 'YES'),('10', '1', '94300', '23700', '3000', '3000', '0', '10', '50000000', 'YES'),('11', '1', '10800', '108500', '3000', '3000', '0', '10', '40000000', 'YES'),('12', '1', '5900', '108500', '3000', '3000', '0', '10', '40000000', 'YES'),('13', '1', '7700', '104300', '3000', '3000', '0', '10', '40000000', 'YES'),('14', '1', '23400', '46200', '3000', '3000', '0', '10', '70000000', 'YES'),('15', '1', '17200', '44400', '3000', '3000', '0', '10', '70000000', 'YES'),('16', '1', '20000', '40100', '3000', '3000', '0', '10', '70000000', 'YES'),('17', '1', '25800', '36900', '3000', '3000', '0', '10', '70000000', 'YES'),('18', '1', '16900', '35800', '3000', '3000', '0', '10', '70000000', 'YES'),('101', '21', '29400', '11400', '3000', '3000', '0', '10', '50000000', 'YES'),('102', '21', '33600', '12700', '3000', '3000', '0', '10', '50000000', 'YES'),('103', '21', '36300', '16300', '3000', '3000', '0', '10', '50000000', 'YES'),('104', '21', '55900', '17200', '3000', '3000', '0', '10', '50000000', 'YES'),('105', '21', '72800', '8500', '3000', '3000', '0', '10', '65000000', 'YES'),('106', '21', '76300', '5400', '3000', '3000', '0', '10', '65000000', 'YES'),('107', '21', '77600', '10200', '3000', '3000', '0', '10', '65000000', 'YES'),('108', '21', '84200', '47200', '3000', '3000', '0', '10', '70000000', 'YES'),('109', '21', '87800', '61000', '3000', '3000', '0', '10', '70000000', 'YES'),('110', '21', '32100', '113800', '3000', '3000', '0', '10', '45000000', 'YES'),('111', '21', '28800', '117200', '3000', '3000', '0', '10', '45000000', 'YES'),('112', '21', '24400', '118700', '3000', '3000', '0', '10', '45000000', 'YES'),('113', '21', '22600', '114400', '3000', '3000', '0', '10', '45000000', 'YES'),('114', '21', '34800', '92300', '3000', '3000', '0', '10', '70000000', 'YES'),('115', '21', '37500', '89000', '3000', '3000', '0', '10', '70000000', 'YES'),('116', '21', '35100', '73600', '3000', '3000', '0', '10', '70000000', 'YES'),('117', '21', '35400', '69200', '3000', '3000', '0', '10', '70000000', 'YES'),('118', '21', '35400', '55600', '3000', '3000', '0', '10', '70000000', 'YES'),('201', '41', '66100', '9400', '3000', '3000', '0', '10', '45000000', 'YES'),('202', '41', '70300', '7900', '3000', '3000', '0', '10', '45000000', 'YES'),('203', '41', '73600', '11500', '3000', '3000', '0', '10', '45000000', 'YES'),('204', '41', '70900', '15100', '3000', '3000', '0', '10', '45000000', 'YES'),('205', '41', '71800', '61900', '3000', '3000', '0', '10', '65000000', 'YES'),('206', '41', '77000', '64100', '3000', '3000', '0', '10', '65000000', 'YES'),('207', '41', '60700', '66800', '3000', '3000', '0', '10', '65000000', 'YES'),('208', '41', '74500', '68200', '3000', '3000', '0', '10', '65000000', 'YES'),('209', '41', '67900', '110800', '3000', '3000', '0', '10', '40000000', 'YES'),('210', '41', '67900', '115700', '3000', '3000', '0', '10', '40000000', 'YES'),('211', '41', '62800', '114800', '3000', '3000', '0', '10', '40000000', 'YES'),('212', '41', '16600', '95300', '3000', '3000', '0', '10', '65000000', 'YES'),('213', '41', '5400', '94100', '3000', '3000', '0', '10', '50000000', 'YES'),('214', '41', '18600', '89300', '3000', '3000', '0', '10', '65000000', 'YES'),('215', '41', '4600', '89800', '3000', '3000', '0', '10', '50000000', 'YES'),('216', '41', '11200', '36000', '3000', '3000', '0', '10', '70000000', 'YES'),('217', '41', '8200', '31800', '3000', '3000', '0', '10', '70000000', 'YES'),('218', '41', '12000', '29200', '3000', '3000', '0', '10', '70000000', 'YES'),('75', '4', '9600', '13100', '3000', '3000', '0', '10', '70000000', 'YES'),('76', '4', '16100', '15600', '3000', '3000', '0', '10', '70000000', 'YES'),('77', '4', '9100', '19500', '3000', '3000', '0', '10', '70000000', 'YES'),('78', '4', '14900', '19500', '3000', '3000', '0', '10', '70000000', 'YES'),('79', '4', '27700', '19500', '3000', '3000', '0', '10', '65000000', 'YES'),('80', '4', '23600', '23000', '3000', '3000', '0', '10', '65000000', 'YES'),('81', '4', '31800', '24200', '3000', '3000', '0', '10', '65000000', 'YES'),('82', '4', '27900', '27300', '3000', '3000', '0', '10', '65000000', 'YES'),('83', '4', '35500', '35400', '3000', '3000', '0', '10', '40000000', 'YES'),('84', '4', '32800', '39300', '3000', '3000', '0', '10', '40000000', 'YES'),('85', '4', '39700', '39600', '3000', '3000', '0', '10', '40000000', 'YES'),('86', '4', '36100', '42700', '3000', '3000', '0', '10', '40000000', 'YES'),('87', '4', '24400', '39000', '3000', '3000', '0', '10', '50000000', 'YES'),('88', '4', '19900', '41600', '3000', '3000', '0', '10', '50000000', 'YES'),('89', '4', '14400', '41700', '3000', '3000', '0', '10', '50000000', 'YES'),('90', '4', '10200', '39100', '3000', '3000', '0', '10', '50000000', 'YES'),('91', '4', '7700', '34600', '3000', '3000', '0', '10', '50000000', 'YES'),('92', '4', '8400', '29500', '3000', '3000', '0', '10', '50000000', 'YES'),('175', '24', '7100', '5200', '3000', '3000', '0', '10', '40000000', 'YES'),('176', '24', '12800', '4800', '3000', '3000', '0', '10', '40000000', 'YES'),('177', '24', '9700', '9900', '3000', '3000', '0', '10', '40000000', 'YES'),('178', '24', '14500', '13300', '3000', '3000', '0', '10', '40000000', 'YES'),('179', '24', '36900', '26000', '3000', '3000', '0', '10', '50000000', 'YES'),('180', '24', '38600', '29800', '3000', '3000', '0', '10', '50000000', 'YES'),('181', '24', '36500', '33900', '3000', '3000', '0', '10', '50000000', 'YES'),('182', '24', '33600', '38600', '3000', '3000', '0', '10', '50000000', 'YES'),('183', '24', '30900', '33500', '3000', '3000', '0', '10', '50000000', 'YES'),('184', '24', '25700', '33500', '3000', '3000', '0', '10', '70000000', 'YES'),('185', '24', '25600', '37800', '3000', '3000', '0', '10', '70000000', 'YES'),('186', '24', '20900', '37800', '3000', '3000', '0', '10', '70000000', 'YES'),('187', '24', '20900', '33700', '3000', '3000', '0', '10', '70000000', 'YES'),('188', '24', '14200', '33700', '3000', '3000', '0', '10', '65000000', 'YES'),('189', '24', '10000', '37100', '3000', '3000', '0', '10', '65000000', 'YES'),('190', '24', '5800', '34800', '3000', '3000', '0', '10', '65000000', 'YES'),('191', '24', '8800', '29800', '3000', '3000', '0', '10', '65000000', 'YES'),('192', '24', '10500', '26100', '3000', '3000', '0', '10', '65000000', 'YES'),('275', '44', '5400', '7700', '3000', '3000', '0', '10', '40000000', 'YES'),('276', '44', '9700', '7300', '3000', '3000', '0', '10', '40000000', 'YES'),('277', '44', '5500', '11500', '3000', '3000', '0', '10', '40000000', 'YES'),('278', '44', '5100', '15500', '3000', '3000', '0', '10', '40000000', 'YES'),('279', '44', '8900', '17900', '3000', '3000', '0', '10', '40000000', 'YES'),('280', '44', '22200', '15600', '3000', '3000', '0', '10', '50000000', 'YES'),('281', '44', '43000', '3700', '3000', '3000', '0', '10', '70000000', 'YES'),('282', '44', '38900', '27200', '3000', '3000', '0', '10', '50000000', 'YES'),('283', '44', '30200', '29900', '3000', '3000', '0', '10', '50000000', 'YES'),('284', '44', '40000', '34500', '3000', '3000', '0', '10', '50000000', 'YES'),('285', '44', '32800', '37000', '3000', '3000', '0', '10', '50000000', 'YES'),('286', '44', '40600', '39300', '3000', '3000', '0', '10', '50000000', 'YES'),('287', '44', '35600', '40600', '3000', '3000', '0', '10', '50000000', 'YES'),('288', '44', '18500', '33600', '3000', '3000', '0', '10', '70000000', 'YES'),('289', '44', '17300', '38500', '3000', '3000', '0', '10', '70000000', 'YES'),('290', '44', '13500', '39400', '3000', '3000', '0', '10', '70000000', 'YES'),('291', '44', '9100', '38700', '3000', '3000', '0', '10', '65000000', 'YES'),('292', '44', '5000', '36300', '3000', '3000', '0', '10', '65000000', 'YES');
INSERT INTO `object_proto` VALUES (14013,'?? ???',20000000,'90010,20/90011,30/90012,20',0,0,0,-10,-10,10,10,20044,2,1),(14014,'??? ???',20000000,'90010,20/90011,30/90012,20',0,0,0,-10,-10,10,10,20045,2,1),(14015,'???? ???',20000000,'90010,20/90011,30/90012,20',0,0,0,-10,-10,10,10,20046,2,1),(14043,'????? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20060,3,1),(14045,'??? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20062,3,1),(14046,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20063,3,1),(14047,'? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20064,3,1),(14048,'? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20065,3,1),(14049,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20066,3,1),(14050,'??? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20067,3,1),(14051,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20068,3,1),(14052,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20069,3,1),(14053,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20070,3,1),(14054,'??? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20071,3,1),(14055,'?? ???',20000000,'90010,15/90011,20/90012,25',0,0,0,-10,-10,10,10,20072,3,1),(14061,'?? ??',25000000,'90010,25/90011,25/90012,25',0,0,0,-10,-10,10,10,20077,4,1),(14062,'?? ??',500000000,'90010,50/90011,50/90012,50',0,0,0,-10,-10,10,10,20078,4,4),(14063,'?? ??',750000000,'90010,75/90011,75/90012,75',0,0,0,-10,-10,10,10,20079,4,4),(14100,'?(1)',20000000,'90010,20/90011,30/90012,25',0,0,0,-10,-10,10,10,0,1,0),(14110,'?(2)',20000000,'90010,20/90011,30/90012,25',0,0,0,-10,-10,10,10,0,1,0),(14120,'?(3)',20000000,'90010,20/90011,30/90012,25',0,0,0,-10,-10,10,10,0,1,0),(14200,'?? ??',3000000,'90011,5/90012,5',0,0,0,-10,-10,10,10,0,0,1),(14300,'?1',300000,'90010,5',0,0,0,-10,-10,10,10,0,0,0),(14301,'?2',300000,'90010,5',0,0,0,-10,-10,10,10,0,0,0),(14302,'?3',300000,'90010,7',0,0,0,-10,-10,10,10,0,0,0),(14303,'?4',300000,'90010,7',0,0,0,-10,-10,10,10,0,0,0),(14304,'?5',300000,'90010,7',0,0,0,-10,-10,10,10,0,0,0),(14305,'?6',300000,'90010,8',0,0,0,-10,-10,10,10,0,0,0),(14306,'?7',300000,'90010,8',0,0,0,-10,-10,10,10,0,0,0),(14307,'?8',300000,'90010,8',0,0,0,-10,-10,10,10,0,0,0),(14308,'?9',300000,'90010,9',0,0,0,-10,-10,10,10,0,0,0),(14309,'?10',300000,'90010,9',0,0,0,-10,-10,10,10,0,0,0),(14400,'??1',2000000,'90011,5',0,0,0,0,0,0,0,0,0,0),(14401,'??2',2000000,'90011,5',0,0,0,0,0,0,0,0,0,0),(14402,'??3',2000000,'90011,7',0,0,0,0,0,0,0,0,0,0),(14403,'??4',2000000,'90011,7',0,0,0,0,0,0,0,0,0,0),(14404,'??5',2000000,'90011,7',0,0,0,0,0,0,0,0,0,0),(14405,'??6',2000000,'90011,9',0,0,0,0,0,0,0,0,0,0),(14406,'??7',2000000,'90011,9',0,0,0,0,0,0,0,0,0,0),(14407,'??8',2000000,'90011,9',0,0,0,0,0,0,0,0,0,0),(14408,'??9',2000000,'90011,9',0,0,0,0,0,0,0,0,0,0);
INSERT INTO `refine_proto` VALUES (1,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(2,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(3,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(4,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(5,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(6,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(7,30053,1,0,0,0,0,0,0,0,0,30000,0,0,54),(8,30073,2,0,0,0,0,0,0,0,0,45000,0,0,45),(9,30033,2,0,0,0,0,0,0,0,0,75000,0,0,36),(10,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(11,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(12,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(13,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(14,30030,2,0,0,0,0,0,0,0,0,13000,0,0,72),(15,30075,2,0,0,0,0,0,0,0,0,20000,0,0,63),(16,30056,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(17,30022,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(18,30067,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(19,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(20,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(21,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(22,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(23,30079,1,0,0,0,0,0,0,0,0,20000,0,0,54),(24,30015,1,0,0,0,0,0,0,0,0,30000,0,0,45),(25,30016,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(26,30089,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(27,30091,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(28,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(29,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(30,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(31,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(32,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(33,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(34,30034,2,0,0,0,0,0,0,0,0,30000,0,0,54),(35,30011,2,0,0,0,0,0,0,0,0,45000,0,0,45),(36,30035,2,0,0,0,0,0,0,0,0,75000,0,0,36),(37,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(38,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(39,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(40,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(41,30052,2,0,0,0,0,0,0,0,0,13000,0,0,72),(42,30046,2,0,0,0,0,0,0,0,0,20000,0,0,63),(43,30045,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(44,30025,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(45,30058,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(46,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(47,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(48,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(49,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(50,30083,2,0,0,0,0,0,0,0,0,20000,0,0,54),(51,30060,2,0,0,0,0,0,0,0,0,30000,0,0,45),(52,30061,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(53,30088,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(54,30019,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(55,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(56,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(57,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(58,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(59,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(60,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(61,30070,2,0,0,0,0,0,0,0,0,30000,0,0,54),(62,30072,2,0,0,0,0,0,0,0,0,45000,0,0,45),(63,30017,2,0,0,0,0,0,0,0,0,75000,0,0,36),(64,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(65,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(66,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(67,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(68,30041,1,0,0,0,0,0,0,0,0,13000,0,0,72),(69,30008,2,0,0,0,0,0,0,0,0,20000,0,0,63),(70,30057,1,27799,1,0,0,0,0,0,0,40000,0,0,54),(71,30081,1,27987,1,0,0,0,0,0,0,70000,0,0,45),(72,30077,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(73,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(74,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(75,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(76,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(77,30009,2,0,0,0,0,0,0,0,0,20000,0,0,54),(78,30039,2,0,0,0,0,0,0,0,0,30000,0,0,45),(79,30040,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(80,30048,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(81,30090,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(82,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(83,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(84,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(85,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(86,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(87,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(88,30031,1,0,0,0,0,0,0,0,0,30000,0,0,54),(89,30032,2,0,0,0,0,0,0,0,0,45000,0,0,45),(90,30033,2,0,0,0,0,0,0,0,0,75000,0,0,36),(91,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(92,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(93,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(94,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(95,30008,2,0,0,0,0,0,0,0,0,13000,0,0,72),(96,30075,2,0,0,0,0,0,0,0,0,20000,0,0,63),(97,30006,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(98,30022,1,27987,1,0,0,0,0,0,0,70000,0,0,45),(99,30067,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(100,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(101,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(102,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(103,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(104,30079,1,0,0,0,0,0,0,0,0,20000,0,0,54),(105,30015,1,0,0,0,0,0,0,0,0,30000,0,0,45),(106,30086,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(107,30050,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(108,30091,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(109,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(110,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(111,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(112,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(113,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(114,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(115,30071,2,0,0,0,0,0,0,0,0,30000,0,0,54),(116,30018,2,0,0,0,0,0,0,0,0,45000,0,0,45),(117,30017,2,0,0,0,0,0,0,0,0,75000,0,0,36),(118,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(119,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(120,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(121,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(122,30005,2,0,0,0,0,0,0,0,0,13000,0,0,72),(123,30076,2,0,0,0,0,0,0,0,0,20000,0,0,63),(124,30051,1,27799,1,0,0,0,0,0,0,40000,0,0,54),(125,30081,1,27987,1,0,0,0,0,0,0,70000,0,0,45),(126,30047,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(127,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(128,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(129,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(130,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(131,30009,1,0,0,0,0,0,0,0,0,20000,0,0,54),(132,30080,1,0,0,0,0,0,0,0,0,30000,0,0,45),(133,30040,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(134,30049,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(135,30090,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(136,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(137,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(138,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(139,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(140,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(141,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(142,30038,1,0,0,0,0,0,0,0,0,30000,0,0,54),(143,30023,2,0,0,0,0,0,0,0,0,45000,0,0,45),(144,30074,2,0,0,0,0,0,0,0,0,75000,0,0,36),(145,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(146,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(147,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(148,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(149,30007,2,0,0,0,0,0,0,0,0,13000,0,0,72),(150,30078,2,0,0,0,0,0,0,0,0,20000,0,0,63),(151,30045,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(152,30055,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(153,30047,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(154,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(155,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(156,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(157,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(158,30059,2,0,0,0,0,0,0,0,0,20000,0,0,54),(159,30080,2,0,0,0,0,0,0,0,0,30000,0,0,45),(160,30085,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(161,30014,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(162,30042,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(163,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(164,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(165,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(166,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(167,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(168,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(169,30010,2,0,0,0,0,0,0,0,0,30000,0,0,54),(170,30031,1,0,0,0,0,0,0,0,0,45000,0,0,45),(171,30032,2,0,0,0,0,0,0,0,0,75000,0,0,36),(172,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(173,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(174,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(175,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(176,30021,2,0,0,0,0,0,0,0,0,13000,0,0,72),(177,30008,2,0,0,0,0,0,0,0,0,20000,0,0,63),(178,30057,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(179,30006,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(180,30022,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(181,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(182,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(183,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(184,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(185,30082,2,0,0,0,0,0,0,0,0,20000,0,0,54),(186,30079,2,0,0,0,0,0,0,0,0,30000,0,0,45),(187,30087,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(188,30086,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(189,30050,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(190,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(191,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(192,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(193,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(194,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(195,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(196,30038,2,0,0,0,0,0,0,0,0,30000,0,0,54),(197,30011,2,0,0,0,0,0,0,0,0,45000,0,0,45),(198,30074,1,0,0,0,0,0,0,0,0,75000,0,0,36),(199,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(200,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(201,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(202,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(203,30007,2,0,0,0,0,0,0,0,0,13000,0,0,72),(204,30046,2,0,0,0,0,0,0,0,0,20000,0,0,63),(205,30045,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(206,30055,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(207,30058,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(208,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(209,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(210,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(211,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(212,30059,2,0,0,0,0,0,0,0,0,20000,0,0,54),(213,30060,2,0,0,0,0,0,0,0,0,30000,0,0,45),(214,30061,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(215,30014,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(216,30042,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(217,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(218,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(219,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(220,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(221,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(222,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(223,30071,2,0,0,0,0,0,0,0,0,30000,0,0,54),(224,30023,1,0,0,0,0,0,0,0,0,45000,0,0,45),(225,30074,2,0,0,0,0,0,0,0,0,75000,0,0,36),(226,0,0,0,0,0,0,0,0,0,0,1000,0,0,96),(227,0,0,0,0,0,0,0,0,0,0,2000,0,0,93),(228,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(229,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(230,30005,1,0,0,0,0,0,0,0,0,13000,0,0,72),(231,30078,1,0,0,0,0,0,0,0,0,20000,0,0,63),(232,30051,1,27799,1,0,0,0,0,0,0,40000,0,0,54),(233,30055,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(234,30047,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(235,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(236,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(237,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(238,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(239,30059,2,0,0,0,0,0,0,0,0,20000,0,0,54),(240,30080,2,0,0,0,0,0,0,0,0,30000,0,0,45),(241,30085,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(242,30049,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(243,30042,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(244,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(245,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(246,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(247,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(248,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(249,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(250,30070,2,0,0,0,0,0,0,0,0,30000,0,0,54),(251,30018,2,0,0,0,0,0,0,0,0,45000,0,0,45),(252,30017,2,0,0,0,0,0,0,0,0,75000,0,0,36),(253,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(254,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(255,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(256,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(257,30041,2,0,0,0,0,0,0,0,0,13000,0,0,72),(258,30076,2,0,0,0,0,0,0,0,0,20000,0,0,63),(259,30051,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(260,30081,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(261,30077,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(262,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(263,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(264,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(265,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(266,30009,2,0,0,0,0,0,0,0,0,20000,0,0,54),(267,30039,2,0,0,0,0,0,0,0,0,30000,0,0,45),(268,30040,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(269,30048,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(270,30090,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(271,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(272,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(273,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(274,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(275,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(276,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(277,30010,1,0,0,0,0,0,0,0,0,30000,0,0,54),(278,30072,2,0,0,0,0,0,0,0,0,45000,0,0,45),(279,30032,1,0,0,0,0,0,0,0,0,75000,0,0,36),(280,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(281,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(282,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(283,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(284,30021,1,0,0,0,0,0,0,0,0,13000,0,0,72),(285,30008,1,0,0,0,0,0,0,0,0,20000,0,0,63),(286,30057,1,27799,1,0,0,0,0,0,0,40000,0,0,54),(287,30006,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(288,30077,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(289,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(290,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(291,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(292,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(293,30082,2,0,0,0,0,0,0,0,0,20000,0,0,54),(294,30039,2,0,0,0,0,0,0,0,0,30000,0,0,45),(295,30087,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(296,30086,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(297,30050,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(298,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(299,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(300,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(301,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(302,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(303,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(304,30053,1,0,0,0,0,0,0,0,0,30000,0,0,54),(305,30073,1,0,0,0,0,0,0,0,0,45000,0,0,45),(306,30035,2,0,0,0,0,0,0,0,0,75000,0,0,36),(307,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(308,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(309,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(310,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(311,30030,2,0,0,0,0,0,0,0,0,13000,0,0,72),(312,30075,2,0,0,0,0,0,0,0,0,20000,0,0,63),(313,30056,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(314,30025,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(315,30067,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(316,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(317,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(318,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(319,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(320,30083,2,0,0,0,0,0,0,0,0,20000,0,0,54),(321,30015,2,0,0,0,0,0,0,0,0,30000,0,0,45),(322,30016,2,27992,1,0,0,0,0,0,0,45000,0,0,36),(323,30089,2,27993,1,0,0,0,0,0,0,90000,0,0,27),(324,30019,2,27994,1,0,0,0,0,0,0,150000,0,0,18),(325,0,0,0,0,0,0,0,0,0,0,600,0,0,90),(326,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(327,0,0,0,0,0,0,0,0,0,0,2500,0,0,90),(328,0,0,0,0,0,0,0,0,0,0,5000,0,0,90),(329,0,0,0,0,0,0,0,0,0,0,10000,0,0,81),(330,0,0,0,0,0,0,0,0,0,0,20000,0,0,63),(331,30034,2,0,0,0,0,0,0,0,0,30000,0,0,54),(332,30073,2,0,0,0,0,0,0,0,0,45000,0,0,45),(333,30035,2,0,0,0,0,0,0,0,0,75000,0,0,36),(334,0,0,0,0,0,0,0,0,0,0,1000,0,0,90),(335,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(336,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(337,0,0,0,0,0,0,0,0,0,0,8000,0,0,81),(338,30052,2,0,0,0,0,0,0,0,0,13000,0,0,72),(339,30046,2,0,0,0,0,0,0,0,0,20000,0,0,63),(340,30056,2,27799,1,0,0,0,0,0,0,40000,0,0,54),(341,30025,2,27987,1,0,0,0,0,0,0,70000,0,0,45),(342,30058,2,27987,1,0,0,0,0,0,0,120000,0,0,36),(343,0,0,0,0,0,0,0,0,0,0,1200,0,0,90),(344,0,0,0,0,0,0,0,0,0,0,2500,0,0,81),(345,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(346,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(347,30083,2,0,0,0,0,0,0,0,0,20000,0,0,54),(348,30060,2,0,0,0,0,0,0,0,0,30000,0,0,45),(349,30061,2,30193,2,0,0,0,0,0,0,45000,0,0,36),(350,30088,2,30193,4,0,0,0,0,0,0,90000,0,0,27),(351,30019,2,30193,6,0,0,0,0,0,0,150000,0,0,18),(352,0,0,0,0,0,0,0,0,0,0,3000,0,0,90),(353,0,0,0,0,0,0,0,0,0,0,6000,0,0,90),(354,0,0,0,0,0,0,0,0,0,0,12000,0,0,90),(355,0,0,0,0,0,0,0,0,0,0,25000,0,0,81),(356,0,0,0,0,0,0,0,0,0,0,40000,0,0,72),(357,0,0,0,0,0,0,0,0,0,0,60000,0,0,63),(358,0,0,0,0,0,0,0,0,0,0,90000,0,0,54),(359,0,0,0,0,0,0,0,0,0,0,120000,0,0,45),(360,0,0,0,0,0,0,0,0,0,0,150000,0,0,36),(400,30192,2,0,0,0,0,0,0,0,0,20000,0,0,54),(401,30194,2,0,0,0,0,0,0,0,0,30000,0,0,45),(402,0,0,0,0,0,0,0,0,0,0,5000,0,0,72),(403,0,0,0,0,0,0,0,0,0,0,10000,0,0,63),(404,30083,2,0,0,0,0,0,0,0,0,20000,0,0,54),(405,30060,2,0,0,0,0,0,0,0,0,30000,0,0,45),(406,30061,2,30193,2,0,0,0,0,0,0,45000,0,0,36),(407,30088,2,30193,4,0,0,0,0,0,0,90000,0,0,27),(408,30019,2,30193,6,0,0,0,0,0,0,150000,0,0,18),(426,0,0,0,0,0,0,0,0,0,0,2000,0,0,90),(427,0,0,0,0,0,0,0,0,0,0,4000,0,0,90),(428,0,0,0,0,0,0,0,0,0,0,8000,0,0,90),(429,0,0,0,0,0,0,0,0,0,0,16000,0,0,81),(430,30005,1,0,0,0,0,0,0,0,0,26000,0,0,72),(431,30078,1,0,0,0,0,0,0,0,0,40000,0,0,63),(432,30051,1,27799,1,0,0,0,0,0,0,80000,0,0,54),(433,30055,2,27987,1,0,0,0,0,0,0,150000,0,0,45),(434,30047,2,27987,1,0,0,0,0,0,0,240000,0,0,36),(501,25040,2,70031,1,0,0,0,0,0,0,100000,0,0,100),(502,0,0,0,0,0,0,0,0,0,0,120000,0,0,90),(503,0,0,0,0,0,0,0,0,0,0,140000,0,0,90),(504,0,0,0,0,0,0,0,0,0,0,170000,0,0,81),(505,0,0,0,0,0,0,0,0,0,0,200000,0,0,72),(506,0,0,0,0,0,0,0,0,0,0,240000,0,0,63),(507,30050,2,0,0,0,0,0,0,0,0,290000,0,0,54),(508,30083,2,27992,1,0,0,0,0,0,0,340000,0,0,45),(509,30040,2,27993,1,0,0,0,0,0,0,410000,0,0,36),(510,30089,2,27994,1,0,0,0,0,0,0,500000,0,0,36),(531,0,0,0,0,0,0,0,0,0,0,7500,0,0,90),(532,0,0,0,0,0,0,0,0,0,0,15000,0,0,81),(533,0,0,0,0,0,0,0,0,0,0,25000,0,0,72),(534,30196,2,0,0,0,0,0,0,0,0,40000,0,0,63),(535,30090,3,0,0,0,0,0,0,0,0,65000,0,0,54),(536,30195,2,0,0,0,0,0,0,0,0,90000,0,0,45),(537,30197,4,27992,1,0,0,0,0,0,0,120000,0,0,36),(538,30198,2,27993,1,0,0,0,0,0,0,150000,0,0,27),(539,30199,2,27994,1,0,0,0,0,0,0,200000,0,0,18),(701,0,0,0,0,0,0,0,0,0,0,500000,0,0,45),(702,0,0,0,0,0,0,0,0,0,0,2000000,0,0,25),(703,0,0,0,0,0,0,0,0,0,0,0,0,0,100),(751,0,0,0,0,0,0,0,0,0,0,100000,0,0,45),(752,0,0,0,0,0,0,0,0,0,0,500000,0,0,54),(753,0,0,0,0,0,0,0,0,0,0,2000000,0,0,36),(758,71123,2,71129,3,0,0,0,0,0,0,125000,0,0,100),(759,71123,3,71129,4,0,0,0,0,0,0,200000,0,0,100);
INSERT INTO `shop` VALUES (1,'????',9001),(2,'?????',9009),(3,'????',9003),(4,'?????',9002),(5,'imba_shop2',9007),(6,'imba_shop1',9008),(1001,'all_sword',20086),(1002,'all_dualhand_sword',0),(1003,'all_bow',0),(1004,'all_twohand_sword',0),(1005,'all_bell',0),(1006,'all_fan',0),(1007,'all_warrior_armour',20087),(1008,'all_assassin_armour',0),(1009,'all_sura_armour',0),(1010,'all_shaman_armour',0),(1011,'all_warrior_helmet',0),(1012,'all_assassin_helmet',0),(1013,'all_sura_helmet',0),(1014,'all_shaman_helmet',0),(1015,'all_shield',0),(1016,'all_bracelet',0),(1017,'all_shoe',0),(1018,'all_necklace',0),(1019,'all_ring',0),(7,'gold_bar_shop',9005),(8,'firework_shop',9004),(9,'?? ???',20042),(10,'pick_shop',20015),(2000,'hairstyles_mage',20094),(2001,'hairstyles_ninja',20094),(2002,'hairstyles_warrior',20094),(2003,'hairstyles_sura',20094);
INSERT INTO `shop_item` VALUES (1,20,1),(1,40,1),(1,60,1),(1,80,1),(1,1040,1),(1,2010,1),(1,2030,1),(1,2050,1),(1,2070,1),(1,3010,1),(1,3030,1),(1,3050,1),(1,3070,1),(1,4000,1),(1,4010,1),(1,4020,1),(1,5010,1),(1,5030,1),(1,7010,1),(1,7030,1),(1,7050,1),(1,8000,100),(1,8000,200),(2,27400,1),(2,27600,1),(2,27610,1),(2,27800,5),(2,27800,50),(2,27801,5),(2,27801,50),(3,14000,1),(3,15000,1),(3,16000,1),(3,17000,1),(3,22010,5),(3,27001,20),(3,27001,200),(3,27002,20),(3,27002,200),(3,27003,20),(3,27003,200),(3,27004,20),(3,27004,200),(3,27005,20),(3,27005,200),(3,27006,20),(3,27006,200),(3,27103,10),(3,27104,10),(3,27105,10),(3,27110,10),(3,50200,1),(3,50901,10),(3,71113,5),(4,11200,1),(4,11220,1),(4,11230,1),(4,11400,1),(4,11420,1),(4,11430,1),(4,11600,1),(4,11620,1),(4,11630,1),(4,11800,1),(4,11820,1),(4,11830,1),(4,12200,1),(4,12340,1),(4,12480,1),(4,12620,1),(4,13000,1),(5,3100,1),(5,5020,1),(5,5030,1),(5,5040,1),(5,5050,1),(5,5070,1),(5,5080,1),(5,7020,1),(5,7050,1),(5,7060,1),(5,7090,1),(5,7100,1),(6,14000,1),(6,14020,1),(6,14040,1),(6,14060,1),(6,14080,1),(6,14140,1),(6,15000,1),(6,15020,1),(6,15040,1),(6,15060,1),(6,15080,1),(6,15160,1),(6,16000,1),(6,16020,1),(6,16040,1),(6,16060,1),(6,16080,1),(6,16180,1),(6,17000,1),(6,17020,1),(6,17040,1),(6,17060,1),(6,17080,1),(6,17180,1),(7,80003,1),(7,80004,1),(7,80005,1),(7,80006,1),(7,80007,1),(8,50100,100),(8,50101,100),(8,50102,100),(8,50103,100),(8,50104,100),(8,50105,100),(9,11901,1),(9,11903,1),(9,50201,1),(10,29101,1),(11,50054,1),(11,50055,1),(11,50056,1),(1001,15,1),(1001,25,1),(1001,35,1),(1001,45,1),(1001,55,1),(1001,65,1),(1001,75,1),(1001,85,1),(1001,95,1),(1001,105,1),(1001,115,1),(1001,125,1),(1001,135,1),(1002,1000,1),(1002,1010,1),(1002,1020,1),(1002,1030,1),(1002,1040,1),(1002,1050,1),(1002,1060,1),(1002,1070,1),(1002,1080,1),(1002,1090,1),(1002,4000,1),(1002,4010,1),(1002,4020,1),(1003,2000,1),(1003,2010,1),(1003,2020,1),(1003,2030,1),(1003,2040,1),(1003,2050,1),(1003,2060,1),(1003,2070,1),(1003,2080,1),(1003,2090,1),(1003,2100,1),(1003,2110,1),(1003,2120,1),(1003,8000,50),(1003,8000,200),(1004,3000,1),(1004,3010,1),(1004,3020,1),(1004,3030,1),(1004,3040,1),(1004,3050,1),(1004,3060,1),(1004,3070,1),(1004,3080,1),(1004,3090,1),(1004,3100,1),(1004,3110,1),(1004,3120,1),(1005,5000,1),(1005,5010,1),(1005,5020,1),(1005,5030,1),(1005,5040,1),(1005,5050,1),(1005,5060,1),(1005,5070,1),(1005,5080,1),(1006,7000,1),(1006,7010,1),(1006,7020,1),(1006,7030,1),(1006,7040,1),(1006,7050,1),(1006,7060,1),(1006,7070,1),(1006,7080,1),(1006,7090,1),(1006,7100,1),(1006,7110,1),(1006,7120,1),(1007,11200,1),(1007,11210,1),(1007,11220,1),(1007,11230,1),(1007,11240,1),(1007,11250,1),(1007,11260,1),(1008,11400,1),(1008,11410,1),(1008,11420,1),(1008,11430,1),(1008,11440,1),(1008,11450,1),(1008,11460,1),(1009,11600,1),(1009,11610,1),(1009,11620,1),(1009,11630,1),(1009,11640,1),(1009,11650,1),(1009,11660,1),(1010,11800,1),(1010,11810,1),(1010,11820,1),(1010,11830,1),(1010,11840,1),(1010,11850,1),(1010,11860,1),(1011,12200,1),(1011,12220,1),(1011,12240,1),(1012,12340,1),(1012,12360,1),(1012,12380,1),(1013,12480,1),(1013,12500,1),(1013,12520,1),(1014,12620,1),(1014,12640,1),(1014,12660,1),(1015,13000,1),(1015,13040,1),(1016,14000,1),(1016,14020,1),(1016,14040,1),(1016,14060,1),(1016,14080,1),(1016,14100,1),(1016,14120,1),(1016,14140,1),(1016,14160,1),(1016,14180,1),(1016,14200,1),(1017,15000,1),(1017,15020,1),(1017,15040,1),(1017,15060,1),(1017,15080,1),(1017,15100,1),(1017,15120,1),(1017,15140,1),(1017,15160,1),(1017,15180,1),(1017,15200,1),(1017,15220,1),(1018,16000,1),(1018,16020,1),(1018,16040,1),(1018,16060,1),(1018,16080,1),(1018,16100,1),(1018,16120,1),(1018,16140,1),(1018,16160,1),(1018,16180,1),(1018,16200,1),(1019,17000,1),(1019,17020,1),(1019,17040,1),(1019,17060,1),(1019,17080,1),(1019,17100,1),(1019,17120,1),(1019,17140,1),(1019,17160,1),(1019,17180,1),(1019,17200,1),(2000,73751,1),(2000,73752,1),(2000,73753,1),(2000,73754,1),(2000,73755,1),(2000,73756,1),(2000,73757,1),(2000,73758,1),(2000,73759,1),(2000,73760,1),(2000,73761,1),(2000,73762,1),(2001,73251,1),(2001,73252,1),(2001,73253,1),(2001,73254,1),(2001,73255,1),(2001,73256,1),(2001,73257,1),(2001,73258,1),(2001,73259,1),(2001,73260,1),(2001,73261,1),(2001,73262,1),(2002,73001,1),(2002,73002,1),(2002,73003,1),(2002,73004,1),(2002,73005,1),(2002,73006,1),(2002,73007,1),(2002,73008,1),(2002,73009,1),(2002,73010,1),(2002,73011,1),(2002,73012,1),(2003,73501,1),(2003,73502,1),(2003,73503,1),(2003,73504,1),(2003,73505,1),(2003,73506,1),(2003,73507,1),(2003,73508,1),(2003,73509,1),(2003,73510,1),(2003,73511,1),(2003,73512,1);






























