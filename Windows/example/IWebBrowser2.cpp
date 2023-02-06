
// 해당 URL을 이용해 웹 브라우저를 연다.
bool CCopyProperties::OpenNewWindow(LPCTSTR pAddress)
{
	IWebBrowser2 *pWebBrowser;
	HRESULT hr;

	// 웹브라우저 객체를 생성한다.
	hr = ::CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
	if(FAILED(hr) || pWebBrowser == NULL)	return FALSE;

	CString strAddress = pAddress;

	// Navigate()에 필요한 인자들을 초기화한다
	VARIANT vtFlags, vtTarget, vtPostData, vtHeader;
	::VariantInit(&vtFlags);
	::VariantInit(&vtTarget);
	::VariantInit(&vtPostData);
	::VariantInit(&vtHeader);

	// 웹브라우저를 화면에 보이게 한다
	pWebBrowser->put_Visible(VARIANT_TRUE);
	// 사이트를 연다
	hr = pWebBrowser->Navigate(strAddress.AllocSysString(), &vtFlags, &vtTarget, &vtPostData, &vtHeader);

	// 웹브라우저 인터페이스의 참조 횟수를 줄인다
	pWebBrowser->Release();

	return SUCCEEDED(hr);
}