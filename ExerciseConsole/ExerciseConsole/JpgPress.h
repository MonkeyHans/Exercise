
#pragma once

#ifndef JPG_PRESS_H_
#define JPG_PRESS_H_

//function JpgCompress(fileSource: PChar; fileDes: PChar; PressQuality: Integer): Boolean;stdcall;

//bool __stdcall JpgCompress(char* srcFile, char* desFile, int pressQuality);

typedef bool (__stdcall* FJpgCompress)(char* srcFile, char* desFile, int pressQuality);

#endif