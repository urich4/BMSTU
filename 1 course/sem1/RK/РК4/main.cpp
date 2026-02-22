#include <iostream>

using namespace std;

class Bump{
private:
    float power;
public:
    Bump(){}
    Bump(float p){
        power = p;
    }
    float show_power(){
        return power;
    }
};

class Lamp{
protected:
    int len;
    Bump *bumps = new Bump[3];
public:
    Lamp(){}
    Lamp(int n){
        len = n;
        if (n <= 3){
            for (int i = 0; i < n; i++){
                float power = 0;
                cout << "Введите мощность " << i + 1 << " лампочки:";
                cin >> power;
                bumps[i] = Bump(power);
            }   
        }
        else{
            cout << "Максимум 3 лампочки." << endl;
        }
    }

    void show(){
        cout << "Лампа состоит из лампочек:";
        for (int i = 0; i < len; i++){
            cout << "№ " << i << "мощность " << bumps[i].show_power();
        }   
    }

    ~Lamp(){
        delete bumps;
    }
};

class LampPP: public Lamp{
private:
    float min1;
public:
    LampPP(){}
    LampPP(int n, float m): Lamp(n){
        min1 = m * 0.01;
    }

    float max_power(){
        float maxi = 0;
        for (int i = 0; i < len; i++){
            if (maxi < bumps[i].show_power()) maxi = bumps[i].show_power();
        }
        return maxi;
    }
    float min_power(){
        float mini = bumps[0].show_power() * min1;
        for (int i = 0; i < len; i++){
            if (mini > bumps[i].show_power() * min1) mini = min1 * bumps[i].show_power();
        }
        return mini;
    }

    float show_min(){
        return min1;
    }
    ~LampPP(){
        delete bumps;
    }
};

int main(){
    float min2;
    int n;
    cin >> n >> min2;
    LampPP Lustra(n, min2);
    cout << "Максимальная мощность лампы:" << Lustra.max_power() << endl;
    cout << "Минимальная мощность лампы:" << Lustra.min_power() << endl;
    return 0;
}