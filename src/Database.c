#include <sqlite3.h>
#include "Database.h"
#include "game.h"
#include "knob.h"

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))

const char* create_client_table = 
"CREATE TABLE IF NOT EXISTS Customer ("
"   ID INTEGER PRIMARY KEY,"
"   Name TEXT,"
"   Email TEXT"
");";

const char* create_character_table = 
"CREATE TABLE IF NOT EXISTS Character ("
"   CharId INTEGER PRIMARY KEY,"
"   Name TEXT,"
"   Level INTEGER,"
"   Strength INTEGER,"
"   Stamina INTEGER,"
"   Charisma INTEGER,"
"   ClasseId INTEGER,"
"   FOREIGN KEY(ClasseId) REFERENCES Classe(ID)"
");";

const char* create_classe_table = 
"CREATE TABLE IF NOT EXISTS Classe ("
"   ID INTEGER PRIMARY KEY,"
"   RaceId INTEGER,"
"   FactionId INTEGER,"
"   SocialStatusId INTEGER,"
"   FOREIGN KEY(RaceId) REFERENCES Race(ID)"
"   FOREIGN KEY(FactionId) REFERENCES Faction(ID)"
"   FOREIGN KEY(SocialStatusId) REFERENCES SocialStatus(ID)"
");";

const char* create_socialstatus_table = 
"CREATE TABLE IF NOT EXISTS SocialStatus ("
"   ID INTEGER PRIMARY KEY,"
"   Status TEXT"
");";

const char* create_race_table = 
"CREATE TABLE IF NOT EXISTS Race ("
"   ID INTEGER PRIMARY KEY,"
"   Race TEXT"
");";

const char* create_faction_table = 
"CREATE TABLE IF NOT EXISTS Faction ("
"   ID INTEGER PRIMARY KEY,"
"   Faction TEXT"
");";

void StartDatabase(GameData* g) {
    sqlite3_open("store.db", &g->db);
}

void EndDatabase(GameData* g) {
    sqlite3_close(g->db);
}

void InitTables(GameData* g) {

    //Créer la table client
    if (sqlite3_exec(g->db, create_client_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    //Créer la table character
    if (sqlite3_exec(g->db, create_character_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    //Créer la table classe
    if (sqlite3_exec(g->db, create_classe_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    //Créer la table socialstatus
    if (sqlite3_exec(g->db, create_socialstatus_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    //Créer la table race
    if (sqlite3_exec(g->db, create_race_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    //Créer la table faction
    if (sqlite3_exec(g->db, create_faction_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
}
