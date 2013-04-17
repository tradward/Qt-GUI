#include "connector.h"

int Connector::search_p = -1;
int Connector::account_p = -1;
int Connector::signout_p = -1;
int Connector::entry_p = -1;
QString Connector::str = "hello";
bool Connector::tryit = false;

//main window:
QString Connector::s1 = "";
QString Connector::s2 = "";
QString Connector::s3 = "";
QString Connector::s4 = "";
QString Connector::s5 = "";
QString Connector::s6 = "";
QString Connector::s7 = "";
QString Connector::s8 = "";
QString Connector::s9 = "";
QString Connector::s10 = "";
QString Connector::s11 = "";
QString Connector::s12 = "";

//Entry
string Connector::e1 = "";

//Whatsnew
QString Connector::s1_7 = "";
QString Connector::s2_7 = "";
QString Connector::s3_7 = "";
QString Connector::s4_7 = "";
QString Connector::s5_7 = "";
QString Connector::s6_7 = "";
QString Connector::s7_7 = "";
QString Connector::s8_7 = "";
QString Connector::s9_7 = "";
QString Connector::s10_7 = "";
QString Connector::s11_7 = "";
QString Connector::s12_7 = "";


//Movies
QString Connector::s1_3 = "";
QString Connector::s2_3 = "";
QString Connector::s3_3 = "";
QString Connector::s4_3 = "";
QString Connector::s5_3 = "";
QString Connector::s6_3 = "";
string  Connector::movies_type = "";



//Series
QString Connector::s1_8 = "";
QString Connector::s2_8 = "";
QString Connector::s3_8 = "";
QString Connector::s4_8 = "";
QString Connector::s5_8 = "";
QString Connector::s6_8 = "";


//login
QString Connector::username = "";
QString Connector::password = "";


//entry
string Connector::entry_id = "";

//IP
QString Connector::ip = "192.168.1.107";

//search
QString Connector::search_metric = "";

//
string Connector::main_entry[12] = {"","","","","","","","","","","",""};
string Connector::new_entry[12] = {"","","","","","","","","","","",""};

//
string Connector::movies_entry[6] = {"","","","","",""};

string Connector::movies_action_entry[6] = {"","","","","",""};
string Connector::movies_animation_entry[6] = {"","","","","",""};
string Connector::movies_comedy_entry[6] = {"","","","","",""};
string Connector::movies_documentary_entry[6] = {"","","","","",""};
string Connector::movies_drama_entry[6] = {"","","","","",""};

string Connector::movies_family_entry[6] = {"","","","","",""};
string Connector::movies_foreign_entry[6] = {"","","","","",""};
string Connector::movies_horror_entry[6] = {"","","","","",""};
string Connector::movies_music_art_entry[6] = {"","","","","",""};
string Connector::movies_mystery_suspense_entry[6] = {"","","","","",""};

string Connector::movies_romance_entry[6] = {"","","","","",""};
string Connector::movies_science_fiction_entry[6] = {"","","","","",""};
string Connector::movies_sports_entry[6] = {"","","","","",""};
string Connector::movies_war_entry[6] = {"","","","","",""};
string Connector::movies_western_entry[6] = {"","","","","",""};

//
string Connector::series_entry[6] = {"","","","","",""};

string Connector::series_action_entry[6] = {"","","","","",""};
string Connector::series_biography_entry[6] = {"","","","","",""};
string Connector::series_classics_entry[6] = {"","","","","",""};
string Connector::series_comic_entry[6] = {"","","","","",""};
string Connector::series_comedy_entry[6] = {"","","","","",""};
string Connector::series_discovery_entry[6] = {"","","","","",""};

string Connector::series_documentary_entry[6] = {"","","","","",""};
string Connector::series_history_entry[6] = {"","","","","",""};
string Connector::series_kids_entry[6] = {"","","","","",""};
string Connector::series_miniseries_entry[6] = {"","","","","",""};
string Connector::series_reality_entry[6] = {"","","","","",""};
string Connector::series_science_fiction_entry[6] = {"","","","","",""};

string Connector::favorites_entry[10] = {"","","","","","","","","",""};

string Connector::result_entry[10] = {"","","","","","","","","",""};

string Connector::series_type = "";


//entry->favorite?
string Connector::favorite = "0";
QString cp = "Copyright ";
QString cps = "\u00A9";
QString Connector::copyright = cp + cps + " 2013 GROUP02. All rights reserved";