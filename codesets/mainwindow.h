#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCloseEvent>
#include "version.h"
#include "filepub.h"
#include "basetypepub.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace Ui { class CDialogAskText; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

private:
    void showVersion();
    void initactionSets();
    void initVars();
    void initUiOther();
    void readSetting();
    void pubHistorySetting(int type);
    void readHistorySetting();
    void writeHistorySetting();
    WORD32 getAstyleFmt(QStringList filelist);
    void getAstyleConfig();
    void getAstyleOrgConfig();
    void freeArgv();
    void procAstyleInstance(QStringList filelist);
    void showStatus(QString msg);
    void showStatusTimer(QString msg);
    void showTextBrower(QString msg);
    void showTextBrowerAppend(QString msg);
    void getNameFilter();
    void addMenuRecent(QStringList recent, QMenu *pMenu);
    void addMenuCodeFormatRecent();
    void addMenuDocumentRecent();
    void updateRecent(QStringList &list, QString name, QMenu *pMenu);
    //获取对话框输入的文字
    QString getDialogFindText();
    void setLeftTextEdit(QString str);
    void clearLeftTextEdit();
    void setRightTextEdit(QString str);
    void clearRightTextEdit();
public:
    enum{
        TYPE_FILE,
        TYPE_FILES,
        TYPE_DIR,
        TYPE_AUTO,
        TYPE_FILES_NOUI,
        TYPE_DIR_NOUI,
    };

    enum{
        OPENTYPE_YES,
        OPENTYPE_NO,
    };



private:
    Ui::MainWindow *ui;

private:
    QString openFilePathRecent;
    QString openDirPathRecent;
    char **m_argvp;
    WORD32 dwArgc;
    QStringList listAstyleArgv;
    QString logAstyleName;
    QString cfgAstyleName;
    QString cfgAstyleNameOrg;

    QStringList nameFilters;
    QStringList recentfiles_codeformat;
    QStringList recentfiles_document;

    QString m_organization;
    QString m_application;

    QSettings *m_pSettings;

    QString openWordFilePathRecent;
private slots:
    void proc_action_codeFormat_File_trigger();
    void proc_action_codeFormat_Directory_trigger();
    void proc_action_codeFormat_Pub_trigger(int openType, QStringList autolist);
    void proc_menu_codeFormat_Recent_trigger(QAction *action);
    void proc_action_codeFormat_Edit_Config_trigger();
    void proc_action_codeFormat_Save_Config_trigger();
    void proc_action_codeFormat_Del_Config_trigger();
    void proc_action_about_trigger();

    //mysql
    void proc_action_mysql_testdatabase_trigger();
    //office
    void proc_action_office_open_pub_trigger(QString filter, QString openRecent, quint8 openDiagFlag, QStringList openfilelist);
    void proc_action_office_open_trigger();
    void proc_action_office_search_trigger();
    void proc_menu_document_recent_trigger(QAction *action);


};
#endif // MAINWINDOW_H
