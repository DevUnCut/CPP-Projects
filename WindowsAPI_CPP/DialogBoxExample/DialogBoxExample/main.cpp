#include <Windows.h>
#include <shobjidl.h>
#include <iostream>
#include <fstream>

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE prevInstan, PWSTR cmdArg, int cmdShow) {

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	
	if (SUCCEEDED(hr)) {
		// we've successfully created a window, so now let us show a dialog box
		IFileOpenDialog *openDialog;

		// now let us create the open file dialog box
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, (void**)&openDialog);
		if (SUCCEEDED(hr)) {
			// We've successfully created an open file dialog box object, now let us show that window ! !
			hr = openDialog->Show(NULL);

			// let us select the file that we would like to open from within that dialog box 
			IShellItem* pItem;
			hr = openDialog->GetResult(&pItem);

			if (SUCCEEDED(hr)) {
				PWSTR filePath;
				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath);// return back the file path as a string and store in PWSTR filePath variable
				
				if (SUCCEEDED(hr)) { // if we succeeded in generating a string
					// now let us display the selected file name to the user ! !
					MessageBoxW(NULL, filePath, L"the selected file's path is ...", MB_OK);
					std::wfstream file;
					file.open(filePath, std::wfstream::in | std::wfstream::out | std::wfstream::app);
					if (file.is_open()) {
						MessageBoxW(NULL, L"Sucessfully opened the file !", filePath, MB_OK);
						file << L"Hello file !\n";
						file.close();
					}
					CoTaskMemFree(filePath); // free up memory here !
				}
				pItem->Release();
			}
			openDialog->Release();
		}
		CoUninitialize();
	}
	return 0;
}