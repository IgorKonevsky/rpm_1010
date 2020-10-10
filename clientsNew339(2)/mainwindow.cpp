

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setnickname.h"
#include <regex>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    user = new QWebSocket();


    connect(user, &QWebSocket::textMessageReceived,
         [&](const QString& message){
        std::regex rx(".*joined this chat");
        std::string str = message.toStdString();


        if (std::regex_search(str, rx)){
            if (getFirst(str) != nickName)
                enemy = getFirst(str);

            qDebug() << "YOS, HE JOINED REALY: "  << enemy;
        }
        else if (getFirst(str) == enemy + "<hit>"){
        //else if((getFirst(str)==enemy) && (getFirst((getFirst(str).toStdString())) == "<hit>")){

           // QString qStr = getEnd(str);
           // QPushButton *tmpB = findChild<QPushButton *>(qStr);
           // tmpB -> setText("X");

        }
        else if (getFirst(str) == enemy + "<nohit>"){
        //else if((getFirst(str)==enemy) && (getFirst((getFirst(str).toStdString())) == "<nohit>")){

            //QString qStr = getEnd(str);
            //QPushButton *tmpB = findChild<QPushButton *>(qStr);
            // tmpB -> setText("0");
        }
        else{

            int i=0;
            while (i< 100){


                QString it = QString::number(i);
                if(it.length()==1) it = "0" + it;
                //qDebug() << "alarm " << it;
                QString tmp = "f_" + it;
                if (message == "<"+enemy+">" +tmp){

                    QString tmp = "m_"+ it;

                    QPushButton *pb = findChild<QPushButton *>(tmp);



                    if (isAShip(getEnd(message.toStdString()))){
                        qInfo() << user->sendTextMessage((nickName +"<hit> f_" +it).toUtf8());
                        pb->setText("x");
                    }
                    else{
                        qInfo() << user->sendTextMessage((nickName+"<nohit> f_" +it).toUtf8());
                        pb->setText("0");
                        queue = true;
                    }
                    i = 99;
                }
                i++;
            }
        }

         ui->textBrowser->append(message);
    });



    /*for (int i=0; i<100; i++){
          QString it = QString::number(i);
          if(it.length()==1) it = "0" + it;
          QString tmp = "f_" + it;
          QPushButton *pb = findChild<QPushButton *>(tmp);

          connect(pb,&QPushButton::clicked,
                  [&] () {
              qDebug() << tmp;
              qInfo() << user->sendTextMessage(("<"+nickName+">" + tmp).toUtf8());
              //last = pb;
          });}*/


    /*for (int i=0; i<100; i++){
              QString it = QString::number(i);
              if(it.length()==1) it = "0" + it;
              QString tmp = "m_" + it;
              QPushButton *pb = findChild<QPushButton *>(tmp);
              greatTmp = tmp;

              connect(pb,&QPushButton::clicked,
                      [&] () {
                  QString localName = pb->accessibleName();
                  qDebug() << localName;

              });
    }*/
    connect(ui->m_00,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_00";
            ui -> m_00->setText("*");
            iter++;
        }
    });

    connect(ui->m_01,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_01";
            ui -> m_01->setText("*");
            iter++;
        }
    });

    connect(ui->m_02,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_02";
            ui -> m_02->setText("*");
            iter++;
        }
    });

    connect(ui->m_03,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_03";
            ui -> m_03->setText("*");
            iter++;
        }
    });
    connect(ui->m_04,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_04";
            ui -> m_04->setText("*");
            iter++;
        }
    });
    connect(ui->m_05,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_05";
            ui -> m_05->setText("*");
            iter++;
        }
    });
    connect(ui->m_06,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_06";
            ui -> m_06->setText("*");
            iter++;
        }
    });
    connect(ui->m_07,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_07";
            ui -> m_07->setText("*");
            iter++;
        }
    });
    connect(ui->m_08,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_08";
            ui -> m_08->setText("*");
            iter++;
        }
    });
    connect(ui->m_09,&QPushButton::clicked,
            [&] () {
        if (iter<10){
            ships[iter] = "f_09";
            ui -> m_09->setText("*");
            iter++;
        }
    });








    connect(ui->f_00,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_00").toUtf8());
    });

    connect(ui->f_01,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_01").toUtf8());
    });

    connect(ui->f_02,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_02").toUtf8());
    });
    connect(ui->f_03,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_03").toUtf8());
    });
    connect(ui->f_04,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_04").toUtf8());
    });
    connect(ui->f_05,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_05").toUtf8());
    });
    connect(ui->f_06,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_06").toUtf8());
    });
    connect(ui->f_07,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_07").toUtf8());
    });
    connect(ui->f_08,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_08").toUtf8());
    });
    connect(ui->f_09,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_09").toUtf8());
    });
    connect(ui->f_10,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_10").toUtf8());
    });
    connect(ui->f_11,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_11").toUtf8());
    });
    connect(ui->f_12,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_12").toUtf8());
    });
    connect(ui->f_13,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_13").toUtf8());
    });
    connect(ui->f_14,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_14").toUtf8());
    });
    connect(ui->f_15,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_15").toUtf8());
    });
    connect(ui->f_16,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_16").toUtf8());
    });

    connect(ui->f_17,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_17").toUtf8());
    });
    connect(ui->f_18,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_18").toUtf8());
    });
    connect(ui->f_19,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_19").toUtf8());
    });
    connect(ui->f_20,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_20").toUtf8());
    });
    connect(ui->f_21,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_21").toUtf8());
    });
    connect(ui->f_22,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_22").toUtf8());
    });
    connect(ui->f_23,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_23").toUtf8());
    });
    connect(ui->f_24,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_24").toUtf8());
    });
    connect(ui->f_25,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_25").toUtf8());
    });
    connect(ui->f_26,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_26").toUtf8());
    });
    connect(ui->f_27,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_27").toUtf8());
    });
    connect(ui->f_28,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_28").toUtf8());
    });
    connect(ui->f_29,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_29").toUtf8());
    });
    connect(ui->f_30,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_30").toUtf8());
    });
    connect(ui->f_31,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_31").toUtf8());
    });
    connect(ui->f_32,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_32").toUtf8());
    });
    connect(ui->f_33,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_33").toUtf8());
    });
    connect(ui->f_34,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_34").toUtf8());
    });
    connect(ui->f_35,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_35").toUtf8());
    });


    connect(ui->f_36,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_36").toUtf8());
    });
    connect(ui->f_37,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_37").toUtf8());
    });
    connect(ui->f_38,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_38").toUtf8());
    });
    connect(ui->f_39,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_39").toUtf8());
    });
    connect(ui->f_40,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_40").toUtf8());
    });
    connect(ui->f_41,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_41").toUtf8());
    });
    connect(ui->f_42,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_42").toUtf8());
    });
    connect(ui->f_43,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_43").toUtf8());
    });
    connect(ui->f_44,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_44").toUtf8());
    });
    connect(ui->f_45,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_45").toUtf8());
    });
    connect(ui->f_46,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_46").toUtf8());
    });
    connect(ui->f_47,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_47").toUtf8());
    });
    connect(ui->f_48,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_48").toUtf8());
    });
    connect(ui->f_49,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_49").toUtf8());
    });
    connect(ui->f_50,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_50").toUtf8());
    });
    connect(ui->f_51,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_51").toUtf8());
    });
    connect(ui->f_52,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_52").toUtf8());
    });
    connect(ui->f_53,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_53").toUtf8());
    });
    connect(ui->f_54,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_54").toUtf8());
    });
    connect(ui->f_55,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_55").toUtf8());
    });
    connect(ui->f_56,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_56").toUtf8());
    });
    connect(ui->f_57,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_57").toUtf8());
    });
    connect(ui->f_58,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_58").toUtf8());
    });
    connect(ui->f_59,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_59").toUtf8());
    });
    connect(ui->f_60,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_60").toUtf8());
    });
    connect(ui->f_61,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_61").toUtf8());
    });
    connect(ui->f_62,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_62").toUtf8());
    });
    connect(ui->f_63,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_63").toUtf8());
    });
    connect(ui->f_64,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_64").toUtf8());
    });
    connect(ui->f_65,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_65").toUtf8());
    });
    connect(ui->f_66,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_66").toUtf8());
    });
    connect(ui->f_67,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_67").toUtf8());
    });
    connect(ui->f_68,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_68").toUtf8());
    });
    connect(ui->f_69,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_69").toUtf8());
    });
    connect(ui->f_70,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_70").toUtf8());
    });
    connect(ui->f_71,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_71").toUtf8());
    });
    connect(ui->f_72,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_72").toUtf8());
    });
    connect(ui->f_73,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_73").toUtf8());
    });
    connect(ui->f_74,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_74").toUtf8());
    });
    connect(ui->f_75,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_75").toUtf8());
    });
    connect(ui->f_76,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_76").toUtf8());
    });
    connect(ui->f_77,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_77").toUtf8());
    });
    connect(ui->f_78,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_78").toUtf8());
    });
    connect(ui->f_79,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_79").toUtf8());
    });
    connect(ui->f_80,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_80").toUtf8());
    });
    connect(ui->f_81,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_81").toUtf8());
    });
    connect(ui->f_82,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_82").toUtf8());
    });
    connect(ui->f_83,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_83").toUtf8());
    });
    connect(ui->f_84,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_84").toUtf8());
    });
    connect(ui->f_85,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_85").toUtf8());
    });
    connect(ui->f_86,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_86").toUtf8());
    });
    connect(ui->f_87,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_87").toUtf8());
    });
    connect(ui->f_88,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_88").toUtf8());
    });
    connect(ui->f_89,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_89").toUtf8());
    });
    connect(ui->f_90,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_90").toUtf8());
    });
    connect(ui->f_91,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_91").toUtf8());
    });
    connect(ui->f_92,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_92").toUtf8());
    });
    connect(ui->f_93,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_93").toUtf8());
    });
    connect(ui->f_94,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_94").toUtf8());
    });
    connect(ui->f_95,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_95").toUtf8());
    });
    connect(ui->f_96,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_96").toUtf8());
    });
    connect(ui->f_97,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_97").toUtf8());
    });
    connect(ui->f_98,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_98").toUtf8());
    });
    connect(ui->f_99,&QPushButton::clicked,
            [&] () {
        qInfo() << user->sendTextMessage(("<"+nickName+">" + "f_99").toUtf8());
    });


    connect(ui->Connect,&QPushButton::clicked,[&](){
        SetNickName b(this);
        if (b.exec() == QDialog::Accepted){
            user->open(QUrl("ws://" + b.ip() + ":" + b.port()));
            nickName = b.nick();
            qInfo() << "ws://" + b.ip() + ":" + b.port() + nickName;

            connect(user,&QWebSocket::stateChanged,[&](QAbstractSocket::SocketState state){
                 if(state == QAbstractSocket::SocketState::ConnectedState){
                    qInfo() << "Connected!";
                    qInfo() << user->peerAddress();
                    user->sendTextMessage(nickName.toUtf8()+" joined this chat");
                 }
            });

        } else return;

    });
    connect(ui->LogIn, &QPushButton::clicked, [&](){
        ui->textBrowser->append("You were disconnected");
        user->sendTextMessage(nickName.toUtf8()+" left this chat");
        user->close(QWebSocketProtocol::CloseCode::CloseCodeNormal," left this chat");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::isAShip(QString str){

    for (int i=0; i<10; i++){
        if (str == ships[i]) return true;
    }
    return false;
}
QString MainWindow::getEnd(std::string str){
    std::string total;
    int pos = str.find('>');
    total = str.substr(pos+1, (str.length()-pos-1));
    QString ret = QString::fromStdString(total);
    return ret;

}

QString MainWindow::getFirst(std::string str){
    std::string total;
    int pos = str.find(' ');
    total = str.substr(0,pos);
    QString ret = QString::fromStdString(total);
    return ret;

}
