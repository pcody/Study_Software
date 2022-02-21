## 라즈베리파이 mosquitto 명령어

- 설치
  sudo apt-get update
  sudo apt-cache search mosquitto (안 해도 됨)
  sudo apt-get install mosquitto mosquitto-clients
- START : sudo /etc/init.d/mosquitto start
- RESTART : sudo service mosquitto restart
- 활성화 : sudo systemctl enable mosquitto
- conf 설정 변경 : sudo nano /etc/mosquitto/mosquitto.conf
- conf 내용 보기 : cat /etc/mosquitto/mosquitto.conf
- 포트 확인 : netstat -anlp | more
- mosquitto status 확인 : systemctl status mosquitto
- SUB : mosquitto_sub -d -t hello/world
- PUB : mosquitto_pub -d -t mydata/stream -m "ppopoph"





## MQTT 웹소켓 활성화

- mosquitto.conf 맨 아래에 하기 내용 추가

```tex
  #include_dir
  listener 9001
  protocol websockets
  
  #mqtt
  listener 1883
  protocol mqtt
```

- mosquitto.conf 파일이 있는 폴더에서 명령 실행
  mosquitto -c mosquitto.conf -v





## Window CMD mosquitto 명령어

- 실행
  mosquitto -v
- SUB : mosquitto_sub -h 192.168.xxx.xxx -t hello/world
- PUB : mosquitto_pub -h 192.168.xxx.xxx -t hello/world -m "ppopoph"

- Process Kill
  윈도우키 -> 관리자권한으로 cmd 실행
  tasklist | findstr "mosquitto"
  taskkill /f /pid 00000