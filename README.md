# RoomSystemSensorArduino

## 想定環境
- Arduino UNO
- 温度センサ LM61CIZ
- 照度センサ NJL7202L-F3

## 機能

基本的に、
[aoirint/room-system-firebase](https://github.com/aoirint/room-system-firebase)、
[aoirint/RoomSystemBotClient](https://github.com/aoirint/RoomSystemBotClient)
と組み合わせて使うことを想定しています。


### 照度センサ（Light）
部屋の明るさを測定します。

### 温度センサ（Temperature）
部屋の温度を測定します。

### 今行きますボタン（Now Button）
すぐに向かうことを伝えるための物理ボタンです。

### お待ちくださいボタン（Wait Button）
しばらく待ってほしいことを伝えるための物理ボタンです。

### ドア開閉センサ（Door）
電極を取り付けたドアが閉じているか、開いているかを検知します。


## センサの接続

### 照度センサ（Light）
`A0`番ピンに接続してください。

### 温度センサ（Temperature）
`A1`番ピンに接続してください。

### 今行きますボタン（Now Button）
`3`番ピンに接続してください。

### お待ちくださいボタン（Wait Button）
`4`番ピンに接続してください。

### ドア開閉センサ（Door）
`5`番ピンに接続してください。


## コンパイル・書き込み
他のプロセスがデバイスとシリアル通信していると通信できないので、先に止めてください。

```bash
./compile.sh
./upload /dev/ttyACM0
```

## シリアルモニタ
他のプロセスがデバイスとシリアル通信していると通信できないので、先に止めてください。

```bash
./serial.sh
```

閉じるには`Ctrl+A K`を押したあと`y`で`Enter`です。
