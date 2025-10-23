#include<bits/stdc++.h>
using namespace std;

wstring blocks[4];
int main(){
    blocks[0].append(L"0...");
    blocks[0].append(L"0...");
    blocks[0].append(L"0...");
    blocks[0].append(L"0000");

    blocks[1].append(L"...0");
    blocks[1].append(L"...0");
    blocks[1].append(L"...0");
    blocks[1].append(L"0000");

    blocks[2].append(L".0..");
    blocks[2].append(L".00.");
    blocks[2].append(L"..0.");
    blocks[2].append(L"....");

    blocks[3].append(L"..0.");
    blocks[3].append(L".00.");
    blocks[3].append(L".0..");
    blocks[3].append(L"....");

    return 0;
}