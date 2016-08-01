#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/tubiao.ico"));

    QTimer *timer = new QTimer(this);
    time_flag=0;
    start_flag=0;

    //新建定时器

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));

    //关联定时器计满信号和相应的槽函数

    timer->start(1000);

    //定时器开始计时，其中1000表示1000ms即1秒

    for (int i=0;i<6;i++)
    {
        Point[i].x=Point[i].y=-1;
        yanshi[i]=0;
        moshi[i]="zuodan";
    }

    //系统托盘
systray=new QSystemTrayIcon(this);
systray->setIcon(QIcon(":/tubiao.ico"));
systray->setVisible(true);
systray->show();


connect(systray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showmain()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    POINT lpPoint;
//    GetCursorPos(&lpPoint);

   // SetCursorPos(lpPoint.x, lpPoint.y);
    ui->yanshi1->setReadOnly(true);

    SetCursorPos(862,543);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);


}
void MainWindow::mousePressEvent(QMouseEvent *e){
   qDebug()<<e->globalX()<<e->globalY();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(49==event->key()){
       GetCursorPos(&Point[1]);
       ui->x1text->setText(QString::number(Point[1].x));
       ui->y1text->setText(QString::number(Point[1].y));   
       QMessageBox *tishi=new QMessageBox(this);
       tishi->setText("位置1坐标捕获成功\n");
       tishi->setWindowTitle("提示");
       tishi->exec();
       this->show();
       this->activateWindow();
    }
    else if(50==event->key()){
        GetCursorPos(&Point[2]);
        ui->x2text->setText(QString::number(Point[2].x));
        ui->y2text->setText(QString::number(Point[2].y));
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setText("位置2坐标捕获成功\n");
        tishi->setWindowTitle("提示");
        tishi->exec();
        this->show();
         this->activateWindow();
    }
    else if(51==event->key()){
        GetCursorPos(&Point[3]);
        ui->x3text->setText(QString::number(Point[3].x));
        ui->y3text->setText(QString::number(Point[3].y));
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setText("位置3坐标捕获成功\n");
        tishi->setWindowTitle("提示");
        tishi->exec();
        this->show();
         this->activateWindow();
    }
    else if(52==event->key()){
        GetCursorPos(&Point[4]);
        ui->x4text->setText(QString::number(Point[4].x));
        ui->y4text->setText(QString::number(Point[4].y));
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setText("位置4坐标捕获成功\n");
        tishi->setWindowTitle("提示");
        tishi->exec();
        this->show();
         this->activateWindow();
    }
    else if(53==event->key()){
        GetCursorPos(&Point[5]);
        ui->x5text->setText(QString::number(Point[5].x));
        ui->y5text->setText(QString::number(Point[5].y));
        QMessageBox *tishi=new QMessageBox(this);
        tishi->setText("位置5坐标捕获成功\n");
        tishi->setWindowTitle("提示");
        tishi->exec();
        this->show();
         this->activateWindow();
    }
}


void MainWindow::timerUpDate()
{
QDateTime time = QDateTime::currentDateTime();
//获取系统现在的时间
QString str = time.toString("yyyy-MM-dd hh:mm:ss");
//设置系统时间显示格式
ui->label->setText(str);
if( time_flag==0){
    ui->stimetext->setText(str);
}
time_flag=1;
if(start_flag==1){
    if(str==ui->stimetext->text()){
        zhixing();
    }
}
}

void MainWindow::on_pushButton_2_clicked()
{
    SetCursorPos(862,543);
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);

}

void MainWindow::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}



void MainWindow::on_bu1_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "请在需要模拟点击的位置\n"
                   "按下数字1键以捕获坐标\n"
                   "捕获过程请勿点击鼠标!\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    this->hide();
    this->activateWindow();
}

void MainWindow::on_start_clicked()
{
    if( start_flag==0){
        start_flag=1;
        setreadonly(true);

        Point[1].x=ui->x1text->text().toInt(),Point[1].y=ui->y1text->text().toInt();
        Point[2].x=ui->x2text->text().toInt(),Point[2].y=ui->y2text->text().toInt();
        Point[3].x=ui->x3text->text().toInt(),Point[3].y=ui->y3text->text().toInt();
        Point[4].x=ui->x4text->text().toInt(),Point[4].y=ui->y4text->text().toInt();
        Point[5].x=ui->x5text->text().toInt(),Point[5].y=ui->y5text->text().toInt();

        yanshi[1]=ui->yanshi1->text().toInt();
        yanshi[2]=ui->yanshi2->text().toInt();
        yanshi[3]=ui->yanshi2->text().toInt();
        yanshi[4]=ui->yanshi4->text().toInt();



        QMessageBox *tishi=new QMessageBox(this);
        tishi->setText("该界面将隐藏\n"
                       "设定的任务将在指定时刻执行\n"
                       "请务必将需要点击窗口保持在最前端\n"
                       "如果需要停止或修改任务，请从系统托盘调出本窗口");

        tishi->setWindowTitle("提示");
        tishi->exec();
        this->hide();
        ui->start->setText("取消任务");
    }
    else if(start_flag==1){
        start_flag=0;
        setreadonly(false);
        ui->start->setText("开始任务");
    }
}

void MainWindow::on_bu2_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "请在需要模拟点击的位置\n"
                   "按下数字2键以捕获坐标\n"
                   "捕获过程请勿点击鼠标!\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    this->hide();
    this->activateWindow();
}
void MainWindow::zhixing(){
    for(int i=1;i<=5;i++){
        if(Point[i].x==-1) continue;
        SetCursorPos(Point[i].x,Point[i].y);
        if(moshi[i]=="zuodan"){
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        else if(moshi[i]=="zuoshuang"){
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        else if(moshi[i]=="youdan"){
            mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
        }
        sleep(yanshi[i]);
    }

    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("任务执行完毕\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    start_flag=0;
    setreadonly(false);
    ui->start->setText("开始任务");

    this->show();
    this->activateWindow();
}


void MainWindow::on_moshi1_activated(const QString &arg1)
{
    if(arg1=="左键单击"){
        moshi[1]="zuodan";
    }
    else if(arg1=="左键双击"){
         moshi[1]="zuoshuang";
    }
    else if(arg1=="右键单击"){
        moshi[1]="youdan";
    }
}

void MainWindow::on_moshi2_activated(const QString &arg1)
{
    if(arg1=="左键单击"){
        moshi[2]="zuodan";
    }
    else if(arg1=="左键双击"){
         moshi[2]="zuoshuang";
    }
    else if(arg1=="右键单击"){
        moshi[2]="youdan";
    }
}
void MainWindow::showmain(){
    this->show();
     this->activateWindow();
}
void MainWindow::setreadonly(bool flag){

    ui->stimetext->setReadOnly(flag);
    ui->x1text->setReadOnly(flag),ui->y1text->setReadOnly(flag);
    ui->x2text->setReadOnly(flag),ui->y2text->setReadOnly(flag);
    ui->x3text->setReadOnly(flag),ui->y3text->setReadOnly(flag);
    ui->x4text->setReadOnly(flag),ui->y4text->setReadOnly(flag);
    ui->x5text->setReadOnly(flag),ui->y5text->setReadOnly(flag);

    ui->yanshi1->setReadOnly(flag);
    ui->yanshi2->setReadOnly(flag);
    ui->yanshi3->setReadOnly(flag);
    ui->yanshi4->setReadOnly(flag);
}

void MainWindow::on_bu3_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "请在需要模拟点击的位置\n"
                   "按下数字3键以捕获坐标\n"
                   "捕获过程请勿点击鼠标!\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    this->hide();
    this->activateWindow();
}

void MainWindow::on_bu4_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "请在需要模拟点击的位置\n"
                   "按下数字4键以捕获坐标\n"
                   "捕获过程请勿点击鼠标!\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    this->hide();
    this->activateWindow();
}

void MainWindow::on_bu5_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "请在需要模拟点击的位置\n"
                   "按下数字5键以捕获坐标\n"
                   "捕获过程请勿点击鼠标!\n");
    tishi->setWindowTitle("提示");
    tishi->exec();

    this->hide();
    this->activateWindow();
}

void MainWindow::on_moshi3_activated(const QString &arg1)
{
    if(arg1=="左键单击"){
        moshi[3]="zuodan";
    }
    else if(arg1=="左键双击"){
         moshi[3]="zuoshuang";
    }
    else if(arg1=="右键单击"){
        moshi[3]="youdan";
    }
}

void MainWindow::on_moshi4_activated(const QString &arg1)
{
    if(arg1=="左键单击"){
        moshi[4]="zuodan";
    }
    else if(arg1=="左键双击"){
         moshi[4]="zuoshuang";
    }
    else if(arg1=="右键单击"){
        moshi[4]="youdan";
    }
}

void MainWindow::on_moshi5_activated(const QString &arg1)
{
    if(arg1=="左键单击"){
        moshi[5]="zuodan";
    }
    else if(arg1=="左键双击"){
         moshi[5]="zuoshuang";
    }
    else if(arg1=="右键单击"){
        moshi[5]="youdan";
    }
}

void MainWindow::on_test_clicked()
{
    QMessageBox *tishi=new QMessageBox(this);
    tishi->setText("该界面将隐藏\n"
                   "测试完毕后弹出\n");
    tishi->setWindowTitle("提示");
    tishi->exec();
    this->hide();

    Point[1].x=ui->x1text->text().toInt(),Point[1].y=ui->y1text->text().toInt();
    Point[2].x=ui->x2text->text().toInt(),Point[2].y=ui->y2text->text().toInt();
    Point[3].x=ui->x3text->text().toInt(),Point[3].y=ui->y3text->text().toInt();
    Point[4].x=ui->x4text->text().toInt(),Point[4].y=ui->y4text->text().toInt();
    Point[5].x=ui->x5text->text().toInt(),Point[5].y=ui->y5text->text().toInt();

    yanshi[1]=ui->yanshi1->text().toInt();
    yanshi[2]=ui->yanshi2->text().toInt();
    yanshi[3]=ui->yanshi2->text().toInt();
    yanshi[4]=ui->yanshi4->text().toInt();


    for(int i=1;i<=5;i++){
        if(Point[i].x==-1) continue;
        SetCursorPos(Point[i].x,Point[i].y);
        if(moshi[i]=="zuodan"){
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        else if(moshi[i]=="zuoshuang"){
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        else if(moshi[i]=="youdan"){
            mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
            mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
        }
        sleep(yanshi[i]);
    }

    tishi->setText("测试完毕\n");
    tishi->exec();
    this->show();
    this->activateWindow();
}

void MainWindow::on_pushButton_7_clicked() //保存并导出
{
    QFile outfile("out.txt");
    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
          return;
    QTextStream out(&outfile);

    for(int i=1;i<=5;i++){
        out<<Point[i].x<<"\n";
        out<<Point[i].y<<"\n";
        if(i!=5)
        out<<yanshi[i]<<"\n";
    }

    QMessageBox *success =new QMessageBox;
    success->setWindowTitle("提示");
    success->setText("成功导出坐标与延时信息\n"
                     "请到软件运行目录out.txt查看\n");
    success->exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    file= QFileDialog::getOpenFileName(this);
    QFile file(this->file);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
             qDebug()<<"Can't open the file!"<<endl;
    }
   else{
        //1
                QByteArray line= file.readLine();
                QString str(line);
                str.remove("\n");
                ui->x1text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->y1text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->yanshi1->setText(str);

            //2
                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->x2text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->y2text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->yanshi2->setText(str);
            //3
                line= file.readLine();
                 str=QString(line);
                str.remove("\n");
                ui->x3text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->y3text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->yanshi3->setText(str);

                //4
                line= file.readLine();
                 str=QString(line);
                str.remove("\n");
                ui->x4text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->y4text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->yanshi4->setText(str);

                //5
                 line= file.readLine();
                 str=QString(line);
                str.remove("\n");
                ui->x5text->setText(str);

                line= file.readLine();
                str=QString(line);
                str.remove("\n");
                ui->y5text->setText(str);
            }

}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox *success =new QMessageBox;
    success->setWindowTitle("说明");
    success->setText("为使同花顺软件界面能加载完毕，请将延时时间设置为1000ms以上\n"
                     "坐标为-1的点软件在执行任务时将跳过，包括延时时间也不执行");
    success->exec();
}
