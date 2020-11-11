# RoomSystemSensorArduino

## 想定環境
- Arduino UNO
- 温度センサ LM61CIZ
- 照度センサ NJL7202L-F3

## Dependencies
```bash
arduino-cli lib install ArduinoJson
```

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


## シリアル通信
改行で区切られたJSONを送り続けます。

```json
{
  "light": 0,
  "temperature": 175,
  "temperatureCelsius": 14.72,
  "nowButtonIsPressed": false,
  "waitButtonIsPressed": false,
  "doorIsOpen": false
}
```


## センサの接続
デジタルピンの読み取りはArduino内部でプルアップ抵抗をはさむようにしているので、
ONのときにGNDと接続、OFFのときは未接続（読み取りは`HIGH`）になるようにしてください。

### 照度センサ（Light）
`A0`番ピンに接続してください。
NJL7202L-F3の長い端子を5V、短い端子を`A0`と抵抗200kΩ（茶黒赤）でプルダウン。

```
[5V]-[Long]NJL7202L-F3[Short]-T--[PIN A0]
                              L-[200kΩ]--[GND]
```

### 温度センサ（Temperature）
`A1`番ピンに接続してください。

```
(top view)

            (rounded)
           ___--^--___
[5V]-[Left]Temp Sensor[Right]-[GND]
             [Center]
                 L--[PIN A1]
```

### 今行きますボタン（Now Button）
`3`番ピンに接続してください。

### お待ちくださいボタン（Wait Button）
`4`番ピンに接続してください。

### ドア開閉センサ（Door）
`5`番ピンに接続してください。
電極が接触しているとき、`5`番ピンがGNDと接続するようにしてください。
電極はアルミニウム板などをドア本体と壁に貼り付けてドアが閉じたときに接触するようにしてください。

## コンパイル・書き込み
他のプロセスがデバイスとシリアル通信していると通信できないので、先に止めてください。
`/dev/ttyACM0`は適切なシリアルポートに置き換えてください。

```bash
./compile.sh
./upload /dev/ttyACM0
```

## シリアルモニタ
他のプロセスがデバイスとシリアル通信していると通信できないので、先に止めてください。
`/dev/ttyACM0`は適切なシリアルポートに置き換えてください。

```bash
./serial.sh /dev/ttyACM0
```

閉じるには`Ctrl+A K`を押したあと`y`で`Enter`です。
