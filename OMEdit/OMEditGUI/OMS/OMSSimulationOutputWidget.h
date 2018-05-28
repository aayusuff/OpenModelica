/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 * @author Adeel Asghar <adeel.asghar@liu.se>
 */

#ifndef OMSSIMULATIONOUTPUTWIDGET_H
#define OMSSIMULATIONOUTPUTWIDGET_H

#include "OMSSimulationOptions.h"
#include "Util/Utilities.h"
#include "OMSimulator.h"

#include <QWidget>
#include <QProgressBar>
#include <QDateTime>

class ArchivedOMSSimulationItem;

class OMSSimulationOutputWidget : public QWidget
{
  Q_OBJECT
public:
  OMSSimulationOutputWidget(OMSSimulationOptions omsSimulationOptions, QWidget *pParent = 0);
  void simulateCallback(const char* ident, double time, oms_status_enu_t status);
  OMSSimulationOptions getOMSSimulationOptions() {return mOMSSimulationOptions;}
  int isSimulationRunning() {return mIsSimulationRunning;}
private:
  OMSSimulationOptions mOMSSimulationOptions;
  Label *mpSimulationHeading;
  QFrame *mpHorizontalLine;
  Label *mpProgressLabel;
  QProgressBar *mpProgressBar;
  QPushButton *mpCancelSimulationButton;
  ArchivedOMSSimulationItem *mpArchivedOMSSimulationItem;
  QDateTime mResultFileLastModifiedDateTime;
  int mIsSimulationRunning;
signals:
  void sendSimulationProgress(QString ident, double time, oms_status_enu_t status);
public slots:
  void cancelSimulation();
  void simulationProgress(QString ident, double time, oms_status_enu_t status);
protected:
  virtual void keyPressEvent(QKeyEvent *event);
};

#endif // OMSSIMULATIONOUTPUTWIDGET_H
