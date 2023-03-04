// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include <Windows.h>

using namespace std;

struct ActorData
{
    string name;
    int hp;
    int attack;
    int defence;
};


int main()
{
    unordered_map<string, ActorData> actorDataList;


    string str_buf;
    string buf;
    string csvFilePath = "sample.csv";

    // 読み込むcsvファイルを開く(std::ifstreamのコンストラクタで開く)
    std::ifstream csvFile(csvFilePath);


    //最初の1行は飛ばす。
    getline(csvFile, str_buf);
    // getline関数で1行ずつ読み込む(読み込んだ内容はstr_bufに格納)
    while (getline(csvFile, str_buf)) {


        ActorData actorData;
        // 「,」区切りごとにデータを読み込むためにistringstream型にする
        istringstream i_stream(str_buf);

        //名前を読み込む。
        getline(i_stream, buf, ',');
        actorData.name = buf;
        //HPを読み込む。
        getline(i_stream, buf, ',');
        actorData.hp = stoi(buf);
        //Attackを読み込む。
        getline(i_stream, buf, ',');
        actorData.attack = stoi(buf);
        //Defenceを読み込む。
        getline(i_stream, buf, ',');
        actorData.defence = stoi(buf);

        actorDataList[actorData.name] = actorData;
    }


    cout << "PlayerのHPは" << actorDataList["Player"].hp << "です" << endl;
    cout << "EnemyのAttackは" << actorDataList["Enemy"].attack << "です" << endl;
    
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
