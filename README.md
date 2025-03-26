# countdownSyphon 

Outputs an video that counts down to the set date and time. output a video in Syphon. I made this for the VJs. made with openFrameworks. 

このアプリは指定した日時までカウントダウン映像をSyphonで出力します。openFrameworksで作りました。

## Feature

- syphon output available ( https://syphon.github.io/ )
- The text can be moved to any position
- You can change the font, color and size

syphon出力を利用可能。文字を任意の位置・フォント・色・サイズに変更できます

# Usage

1. The executable file is in the "bin.zip". Unzip "bin.zip" to use.
 実行ファイル(アプリ)はbin.zipに入ってます。bin.zipを解凍して使用してください。

2. Edit "bin/settings.xml" if you wish to change the date and time settings.
 日付と時刻の設定を変更したい場合は、「bin/settings.xml」を編集する。

# Build

Generate a project by applying ofxGui and ofxSyphon and ofxXmlSettings with projectGenerator of openFrameworks.

openFrameworksのprojectGeneratorでofxGuiとofxSyphonとofxXmlSettingsを適用してプロジェクトを生成します。

![projectGenerator](img/generateProject.png)

the free font place under openFrameworks/apps/myApps/clockSyphon/bin/data

適当なフリーフォントをopenFrameworks/apps/myApps/clockSyphon/bin/data配下に置く

![projectGenerator](img/bindata.png)

free font フリーフォント https://fonts.google.com/specimen/Lato
