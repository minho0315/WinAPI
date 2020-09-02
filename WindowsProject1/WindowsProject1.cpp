

int APIENTRY wWinMain()
{
    MyRegisterClass(hInstance);
    InitInstance (hInstance, nCmdShow)

    while ()
    { }
}

ATOM MyRegisterClass()
{ wcex.lpfnWndProc    = WndProc;}

BOOL InitInstance()
{CreateWindowW();}

LRESULT CALLBACK WndProc()
{
    switch (message)
    { 
        DialogBox(About);
    }
}

INT_PTR CALLBACK About()
{}
