/*******************************************************************************
 *
 *                                 Silverjuke
 *     Copyright (C) 2016 Björn Petersen Software Design and Development
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 *******************************************************************************
 *
 * File:    upnp_scanner.h
 * Authors: Björn Petersen
 * Purpose: Using UPNP/DLNA devices
 *
 ******************************************************************************/


#ifndef __SJ_UPNP_SCANNER_DLG_H__
#define __SJ_UPNP_SCANNER_DLG_H__
#if SJ_USE_UPNP


#include <sjmodules/scanner/upnp_scanner.h>


#define IDC_MEDIASERVERLISTCTRL   (IDM_FIRSTPRIVATE+2)
#define IDC_MEDIASERVERINFO       (IDM_FIRSTPRIVATE+3)
#define IDC_DIRLISTCTRL           (IDM_FIRSTPRIVATE+10)
#define IDC_DIRENTRYINFO          (IDM_FIRSTPRIVATE+11)
#define IDC_ENABLECHECK           (IDM_FIRSTPRIVATE+12)
#define MSG_UPDATEMEDIASERVERLIST (IDM_FIRSTPRIVATE+50)
#define MSG_SCANDONE              (IDM_FIRSTPRIVATE+51)


class SjUpnpDialog : public SjDialog
{
public:
	                     SjUpnpDialog            (wxWindow* parent, SjUpnpScannerModule*, SjUpnpSource*);
	SjUpnpMediaServer*   GetSelectedMediaServer  ();
	SjUpnpDirEntry*      GetSelectedDir          (); // parent directory if nothing is selected
	void                 GetChanges              (SjUpnpSource*);

private:
	void                 EnableDisable           ();
	void                 UpdateMediaServerList   ();
	void                 UpdateDirList           (const wxString& selId="");
	SjUpnpDirEntry*      GetSelectedDirEntry     (); // null if nothing is selected

	void                 OnEnableCheck           (wxCommandEvent&) { EnableDisable(); }
	void                 OnUpdateMediaServerList (wxCommandEvent&);
	void                 OnScanDone              (wxCommandEvent&);
	void                 OnSize                  (wxSizeEvent& e);
	void                 OnMediaServerClick      (wxListEvent&);
	void                 OnMediaServerContextMenu(wxListEvent&);
	void                 OnMediaServerInfo       (wxCommandEvent&);
	void                 OnDirDoubleClick        (wxListEvent&);
	void                 OnDirContextMenu        (wxListEvent&);
	void                 OnDirEntryInfo          (wxCommandEvent&);

	bool                 m_isNew;
	bool                 m_stillLoading;
	SjUpnpScannerModule* m_upnpModule;

	wxListCtrl*          m_mediaServerListCtrl;
	wxStaticText*        m_stillScanningText;

	SjUpnpDir            m_currDir;
	wxArrayString        m_parentIds, m_parentNames, m_parentSelIds;
	SjUpnpDirEntry       m_parentDirEntry;
	SjUpnpMediaServer*   m_dirListFor;
	wxListCtrl*          m_dirListCtrl;
	wxCheckBox*          m_enabledCheckBox;
	wxCheckBox*          m_doUpdateCheckBox;

	                     DECLARE_EVENT_TABLE ()
};

#endif // SJ_USE_UPNP
#endif // __SJ_UPNP_SCANNER_DLG_H__

