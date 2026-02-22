#ifndef CLASS_H
#define CLASS_H

class Tower{
protected:
    char name[100];
    float high;
    bool pass;
public:
    Tower(const char *n = "",  float h = 0, bool s = 0);
    char* get_name();
    float get_high();
    bool get_pass();
    void show_info();
};

class Castle{
protected:
    char name[100];
    int len;
    Tower *castle;
public: 
    Castle();
    Castle(const char *n = "", int l = 0, Tower *c = {});
    void show_info();
    Tower* hmax();
    int pass_tower();
};


#endif