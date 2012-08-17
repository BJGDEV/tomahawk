/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2010-2011, Leo Franchi <lfranchi@kde.org>
 *   Copyright 2010-2012, Jeff Mitchell <jeff@tomahawk-player.org>
 *   Copyright 2012,      Teo Mrnjavac <teo@kde.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QtGui/QDialog>
#include <QtCore/QModelIndex>
#include <QtGui/QActionGroup>
#include <QtGui/QToolBar>

#include "config.h"

class AnimatedSpinner;
class QListWidgetItem;
class Ui_Settings_Accounts;
class Ui_Settings_Collection;
class Ui_Settings_Advanced;
class SipPlugin;
class ResolversModel;
class QNetworkReply;
class QToolbarTabDialog;

namespace Ui
{
    class ProxyDialog;
}

namespace Tomahawk
{
    namespace Accounts
    {
        class AccountModel;
        class Account;
        class AccountFactory;
class Account;
class AccountModelFilterProxy;
}
}

class ProxyDialog : public QDialog
{
Q_OBJECT

public:
    explicit ProxyDialog( QWidget* parent = 0 );
    ~ProxyDialog() {};

    void saveSettings();

private:
    Ui::ProxyDialog* ui;
};

class SettingsDialog : public QObject
{
Q_OBJECT

public:
    explicit SettingsDialog( QObject* parent = 0 );
    ~SettingsDialog();

    void show();
protected:
    void changeEvent( QEvent* e );

private slots:
    void onRejected();

    void toggleRemoteMode();
    void toggleProxyEnabled();
    void showProxySettings();

    void accountsFilterChanged( int );

    void createAccountFromFactory( Tomahawk::Accounts::AccountFactory* );
    void openAccountConfig( Tomahawk::Accounts::Account*, bool showDelete = false );
    void openAccountFactoryConfig( Tomahawk::Accounts::AccountFactory* );

    void installFromFile();
    void scrollTo( const QModelIndex& );

    void updateScanOptionsView();

    void serventReady();

    void aclEntryClearButtonClicked();

    void requiresRestart();

private slots:
    void saveSettings();

private:
    Ui_Settings_Accounts* m_accountsWidgetUi;
    QWidget* m_accountsWidget;

    Ui_Settings_Collection* m_collectionWidgetUi;
    QWidget* m_collectionWidget;

    Ui_Settings_Advanced* m_advancedWidgetUi;
    QWidget* m_advancedWidget;

    QToolbarTabDialog* m_dialog;

    ProxyDialog m_proxySettings;
    bool m_rejected;
    bool m_restartRequired;
    Tomahawk::Accounts::AccountModel* m_accountModel;
    Tomahawk::Accounts::AccountModelFilterProxy* m_accountProxy;
    AnimatedSpinner* m_sipSpinner;
};

#endif // SETTINGSDIALOG_H

