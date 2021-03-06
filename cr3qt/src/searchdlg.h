#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include <lvstring.h>
#include <QDialog>

namespace Ui {
    class SearchDialog;
}

class CR3View;

class SearchDialog : public QDialog {
    Q_OBJECT
public:
    static bool showDlg( QWidget * parent, CR3View * docView );
    bool findText( lString32 pattern, int origin, bool reverse, bool caseInsensitive );
protected:
    SearchDialog(QWidget *parent, CR3View * docView);
    ~SearchDialog();
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent* e);

private:
    Ui::SearchDialog *ui;
    CR3View * _docview;
    lString32 _lastPattern;
    static SearchDialog* _instance;
private slots:
    void on_btnFindNext_clicked();
    void on_btnClose_clicked();
};

#endif // SEARCHDLG_H
