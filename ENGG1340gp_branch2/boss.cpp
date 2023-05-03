#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
using namespace std;
int boss(Player *player) {
    int player_hp = player->player_hp;
    int player_energy = player->player_energy;
    int player_normal_attack =player->player_normal_attack;
    int player_defense = player->player_defense;
    int boss_hp = 200;
    int boss_normal_attack = 15;
    int round_num = 0;
    bool dis_skill = false;
    bool use_defense = false;
    bool call_troop = false;
    int count = 3;
    srand(time(0)); // 用于生成随机数

    while (player_hp > 0 && boss_hp > 0) {
        round_num++;
        cout << "==================== Round " << round_num << " ====================" << endl;

        // 玩家进攻
        int attack_choice = 0;
        int player_real_attack = player_normal_attack;
        if (call_troop){
            if (count > 0) {
                player_real_attack = player_normal_attack * 2;
                count -= 1;
            }
        }
        if (dis_skill){
            cout << "Player HP: " << player_hp << "  Energy: " << player_energy << endl;
            cout << "Boss HP: " << boss_hp << endl;
            cout << "Please choose your attack:" << endl;
            cout << "1. Normal Attack" << endl;
            cin >> attack_choice;
            while (attack_choice != 1){
                
                cout << "You can only use normal attack now. Please choose again." << endl;
                cin >> attack_choice;
            }
            cout << "Player uses Normal Attack, Boss loses " << player_real_attack << " HP." << endl;
            boss_hp -= player_real_attack;
            dis_skill = false;

        }

        
        else{
            while (attack_choice != 1 && attack_choice != 2 && attack_choice != 3 && attack_choice != 4) {
                cout << "Player HP: " << player_hp << "  Energy: " << player_energy << endl;
                cout << "Boss HP: " << boss_hp << endl;
                cout << "Please choose your attack:" << endl;
                cout << "1. Normal Attack" << endl;
                cout << "2. Defense (cost 1 energy)" << endl;
                cout << "3. Heavy Attack (cost 2 energy)" << endl;
                cout << "4. Call troops (cost 4 energy)" << endl;
                cin >> attack_choice;
                cout << endl;

                if (attack_choice == 2 && player_energy < 1) {
                    cout << "Not enough energy, please choose again." << endl;
                    attack_choice = 0;
                } else if (attack_choice == 3 && player_energy < 2) {
                    cout << "Not enough energy, please choose again." << endl;
                    attack_choice = 0;
                }else if (attack_choice == 4 && player_energy < 4) {
                    cout << "Not enough energy, please choose again." << endl;
                    attack_choice = 0;

                }else if (attack_choice == 4 && call_troop == true) {
                    cout << "You cannot call troop again, please choose again." <<endl;
                    attack_choice = 0;
                }
            }

            if (attack_choice == 1) {
                cout << "Player uses Normal Attack, Boss loses " << player_real_attack << " HP." << endl;
                boss_hp -= player_real_attack;
            } else if (attack_choice == 2) {
                cout << "Player uses Defense" << endl;
                player_energy -= 1;
                use_defense = true;
            } else if (attack_choice == 3) {
                cout << "Player uses Heavy Attack, Boss loses " << player_real_attack * 2 << " HP." << endl;
                boss_hp -= player_real_attack * 2;
                player_energy -= 2;
                
            }
            else{
                cout << "Player calls the troop" << endl;
                call_troop = true;
                player_energy -= 4;

            }
        }

        // Boss 进攻
        int boss_attack_choice = rand() % 7 + 1; // 生成 1-7 的随机数，其中 1-4 表示普通攻击，5-6 表示魔法攻击，7 表示暴击
        int boss_real_attack;
        if (call_troop == true && count > 0){
            boss_real_attack = boss_normal_attack / 2;
        }
        else{
            boss_real_attack = boss_normal_attack;
        if (use_defense == true){
            boss_real_attack = boss_normal_attack - player_defense;
            use_defense = false;
        }
        else{
            boss_real_attack = boss_normal_attack;
        }
        }
        if (boss_attack_choice <= 4) {
            cout << "Boss used Normal Attack, Player loses " << boss_real_attack << " HP." << endl;
            player_hp -= boss_real_attack;
        } else if (boss_attack_choice <= 6) {
            cout << "Boss used Magic Attack, Player loses " << boss_real_attack << " HP and can't use skills next turn." << endl;
            player_hp -= boss_real_attack;
            dis_skill = true;
        } else {
            cout << "Boss used Critical Strike, Player loses " << boss_real_attack * 3 << " HP." << endl;
            player_hp -= boss_real_attack * 3;
        }

        cout << endl;
    }

    // 游戏结束
    if(player_hp<=0) return 0;
    else return 1;
}
        
    