## 라즈베리파이 초기 SSH설정

1. ssh허용하기
   sd Card boot드라이버에 ssh파일 생성 (확장자x)

2. 화면 없이 WiFi 접속
   sd Card boot드라이버에  wpa_supplicant.conf 파일 생성
   아래 두 내용 중 적어서 넣으면 됨

   ```bash
   country=GB 
   ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev 
   update_config=1 
   network={ 
    ssid="WiFi이름" 
    psk="WiFi비밀번호" 
   }
   
   country=US
   ctrl_interface=DIR=/var/run/wpa_supplicant
   GROUP=netdev
   update_config=1
   network={
    ssid="WiFi이름"
    psk="WiFi비밀번호"
    scan_ssid=1
    key_mgmt=WPA-PSK
   }
   ```

   