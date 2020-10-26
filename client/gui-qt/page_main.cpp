/**************************************************************************
 Copyright (c) 1996-2020 Freeciv21 and Freeciv contributors. This file is
 part of Freeciv21. Freeciv21 is free software: you can redistribute it
 and/or modify it under the terms of the GNU  General Public License  as
 published by the Free Software Foundation, either version 3 of the
 License,  or (at your option) any later version. You should have received
 a copy of the GNU General Public License along with Freeciv21. If not,
 see https://www.gnu.org/licenses/.
**************************************************************************/

#include "page_main.h"
// utility
#include "fcintl.h"
// common
#include "version.h"
// gui-qt
#include "fc_client.h"

page_main::page_main(QWidget *parent, fc_client *gui) : QWidget(parent)
{
  const char *rev_ver;
  QString msgbuf;
  QString beta;
  ui.setupUi(this);
  ui.bstart->setText(_("Start new game"));
  ui.bscenario->setText(_("Start scenario game"));
  ui.boptions->setText(_("Options"));
  ui.bload->setText(_("Load saved game"));
  ui.bconnect->setText(_("Connect to network game"));
  ui.bquit->setText(_("Quit"));

  QPixmap main_graphics(tileset_main_intro_filename(tileset));
  ui.lintro->setPixmap(main_graphics);
  ui.lintro->setFixedSize(main_graphics.size());
  connect(ui.bstart, &QAbstractButton::clicked, gui,
          &fc_client::start_new_game);
  connect(ui.bscenario, &QPushButton::clicked,
          [gui]() { gui->switch_page(PAGE_SCENARIO); });
  connect(ui.boptions, &QAbstractButton::clicked,
          [=]() { popup_client_options(); });
  connect(ui.bquit, &QAbstractButton::clicked, gui, &fc_client::quit);
  connect(ui.bconnect, &QPushButton::clicked,
          [gui]() { gui->switch_page(PAGE_NETWORK); });
  connect(ui.bload, &QPushButton::clicked,
          [gui]() { gui->switch_page(PAGE_LOAD); });

  rev_ver = fc_git_revision();

  if (rev_ver == NULL) {
    /* TRANS: "version 2.6.0, Qt client" */
    msgbuf = QString::asprintf(_("%s%s, Qt client"), word_version(),
                               VERSION_STRING);
  } else {
    msgbuf = QString::asprintf("%s%s", word_version(), VERSION_STRING);
    msgbuf += QString::asprintf(_("commit: %s"), rev_ver);
  }
#if IS_BETA_VERSION
  beta = beta_message();
#endif /* IS_BETA_VERSION */
  ui.lversion->setText(QString(msgbuf) + beta);
}

page_main::~page_main() {}
