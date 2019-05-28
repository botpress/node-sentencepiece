echo "starting to build sentencepiece for windows"

call .\scripts\win_sentencepiece_builder.bat

echo "finished building. Preparing to copy library"
echo F | xcopy .\sentencepiece\build\src\Release\sentencepiece.lib .\bin\sentencepiece_lib.lib /Y