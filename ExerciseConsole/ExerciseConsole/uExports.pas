unit uExports;

interface

function JpgCompress(fileSource: PChar; fileDes: PChar; PressQuality: Integer): Boolean;stdcall;

implementation
uses JPEG,SysUtils,Graphics;

function JpgCompress(fileSource: PChar; fileDes: PChar; PressQuality: Integer): Boolean;stdcall;
var
  bmp: TBitmap;
  jpg: TJpegImage;
begin
  Result := False;

  bmp := TBitmap.Create;
  jpg := TJpegImage.Create;

  if(FileExists(fileDes)) then
    DeleteFile(fileDes);

  if pos(UpperCase('.jpg'),UpperCase(fileSource)) <> 0 then //jpg
  begin
    jpg.LoadFromFile(fileSource);
    bmp.Height := jpg.Height;
    bmp.Width := jpg.Width;
    bmp.Canvas.StretchDraw(bmp.Canvas.ClipRect,jpg);
    jpg.Assign(bmp);
    jpg.CompressionQuality := PressQuality;
    jpg.Compress;
    jpg.SaveToFile(fileDes);
    Result := True;
  end;

  bmp.Free;
  jpg.Free;
end;

end.
