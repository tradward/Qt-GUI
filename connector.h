#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QString>

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Connector {
public:
    static int search_p;
    static int account_p;
    static int signout_p;
    static int entry_p;
    static QString str;
    static bool tryit;
    
    //main window:
    static QString s1;
    static QString s2;
    static QString s3;
    static QString s4;
    static QString s5;
    static QString s6;
    static QString s7;
    static QString s8;
    static QString s9;
    static QString s10;
    static QString s11;
    static QString s12;
    
    //entry:
    static string e1;
    
    
    //whatsnew
    static QString s1_7;
    static QString s2_7;
    static QString s3_7;
    static QString s4_7;
    static QString s5_7;
    static QString s6_7;
    
    static QString s7_7;
    static QString s8_7;
    static QString s9_7;
    static QString s10_7;
    static QString s11_7;
    static QString s12_7;
    
    
    //movies
    static QString s1_3;
    static QString s2_3;
    static QString s3_3;
    static QString s4_3;
    static QString s5_3;
    static QString s6_3;
    
    
    
    //series
    static QString s1_8;
    static QString s2_8;
    static QString s3_8;
    static QString s4_8;
    static QString s5_8;
    static QString s6_8;
    
    //login
    static QString username;
    static QString password;
    
    //entry
    static string entry_id;
    
    //IP
    static QString ip;
    
    //main: entry vector
    static string main_entry[12];
    
    //whatsnew: entry vector
    static string new_entry[12];
    
    //movies: entry vector
    static string movies_type;
    
    static string movies_entry[6];
    
    static string movies_action_entry[6];
    static string movies_animation_entry[6];
    static string movies_comedy_entry[6];
    static string movies_documentary_entry[6];
    static string movies_drama_entry[6];
    
    static string movies_family_entry[6];
    static string movies_foreign_entry[6];
    static string movies_horror_entry[6];
    static string movies_music_art_entry[6];
    static string movies_mystery_suspense_entry[6];
    
    static string movies_romance_entry[6];
    static string movies_science_fiction_entry[6];
    static string movies_sports_entry[6];
    static string movies_war_entry[6];
    static string movies_western_entry[6];
    
    //series: entry vector
    static string series_type;
    
    static string series_entry[6];
    
    static string series_action_entry[6];
    static string series_biography_entry[6];
    static string series_classics_entry[6];
    static string series_comic_entry[6];
    static string series_comedy_entry[6];
    static string series_discovery_entry[6];
    
    static string series_documentary_entry[6];
    static string series_history_entry[6];
    static string series_kids_entry[6];
    static string series_miniseries_entry[6];
    static string series_reality_entry[6];
    static string series_science_fiction_entry[6];
    
    //favorite: entry vector
    static string favorites_entry[10];
    
    //search
    static QString search_metric;
    
    //result
    static string result_entry[10];

    //entry->favorite?
    static string favorite;

    static QString copyright;
    
};
#endif
