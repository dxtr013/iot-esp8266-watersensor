#include <pgmspace.h>
 
#define SECRET
 
const char WIFI_SSID[] = "DESKTOP-DQJ2D0N";               //TAMIM2.4G
const char WIFI_PASSWORD[] = "36*7p6F5";           //0544287380
 
#define THINGNAME "esp8266"
 
int8_t TIME_ZONE = 1; //NYC(USA): -5 UTC
 
const char MQTT_HOST[] = "a2n3vwfw2rcj3h-ats.iot.us-east-1.amazonaws.com";
 
 
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
 
// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAK20+g9Vn+QbC/askmqpGNB7Y7AkMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzAyMDQxMDQw
MTJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC4Gh5pcbxJ6+LcH82I
U8RltamNatz2g5ZmGK8h58CuiKkoLpEcZwZ9/MQPtFSw/GuR2a3u4Fo534zE88Lp
lBZ6SLtBOl30F9XugcfEq78Y0wxZlcDDZhNPzABbvGFG0XjdA2PYLzNA7LMwp108
p2vXZldSdYI8IGBhh3fTDa3VOoW84IbEDv1Pmnav+1X6t2jLGBK9xl7V1Wtuj/ES
6VpW/KlTGwGJqzukaKRFy16cduWYGRzoRi+GRMt34+A3H735wW57Q61FoRC18F9S
EUkxPERZK5+FAo/2pDawj++/+oh8kKt4r2DDd9++jyem0XmJEs15iweJjifF7ejF
mz+VAgMBAAGjYDBeMB8GA1UdIwQYMBaAFJf5dqrlFlmm35ip8tL2z2jT1dwMMB0G
A1UdDgQWBBTRzSUu4eB+plD5c0Vf1MJIViFXrjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAnjfpqq73oLSiDY7B1kJel9f3
WCPx6b9d0iRdghPe0tFkpyzEca3kn3HhF/KZ+64MC1wGgNI74idmoIFjplg1xOsD
S8KqC9tjjz/AZ792tWzLCNe9m8yF5INiqmuPx/J0zyzbhEHBQr69yxI/ULZBqSJe
ANhT9TOkcMWNf0GkFYQaL/itxia+Sw9RIZFv4vmh99gpmihfbHoOvxvv76tntbsx
0Y7RWTVoYSp1+tKE3Q7GMhQOFHRbTMyp1WmD9ddLy01G+AiMa8dZGBxYm8bltRrN
L7IY/SFkQLSWG8SrU8I8zrBTDkxcPxqGqrewu1sl/vP9CTWZr3KyaBbVAqz3bg==
-----END CERTIFICATE-----
)KEY";
 
 
// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAuBoeaXG8Sevi3B/NiFPEZbWpjWrc9oOWZhivIefAroipKC6R
HGcGffzED7RUsPxrkdmt7uBaOd+MxPPC6ZQWeki7QTpd9BfV7oHHxKu/GNMMWZXA
w2YTT8wAW7xhRtF43QNj2C8zQOyzMKddPKdr12ZXUnWCPCBgYYd30w2t1TqFvOCG
xA79T5p2r/tV+rdoyxgSvcZe1dVrbo/xEulaVvypUxsBias7pGikRctenHblmBkc
6EYvhkTLd+PgNx+9+cFue0OtRaEQtfBfUhFJMTxEWSufhQKP9qQ2sI/vv/qIfJCr
eK9gw3ffvo8nptF5iRLNeYsHiY4nxe3oxZs/lQIDAQABAoIBAEsf5V8T2Ui06Br5
I07JF/CFI84gWFCDu8Cnu/dy8Y6HF7fc4LwdUmng1kSuSoz6RA79K9u5Uzggf/ny
movkMRPvT/I7FhHAFD1CWjln+A/yNyzrTgCuS50ZWuAUTAGxAsf1VS3nfNu2exyU
fxh8HSaFjYaJiv5sG8hQllXaVCAZEsVgCVSHr8fieB/tWzKryHw5y7G6+7BBmVm6
XqsCHAflNqgYbpTFT85N03hJXQvZj+OctP3FNUyko0rNhgztE3iKgAliqrWQFmsP
vKnJ4rnO2rxQNXzPzAan6zeMIdKMt5pqGw5g69n50FoVkrpJB7QW/mxAAjn6dr1Y
k0UMeCECgYEA6dDVrS1xO9+aWUWTLpHKunaxyoqbCcffiEV7eC/IngxhETDp16er
BsdRijWiZzDP5WGe9eCwZ2NEwDaXuKe8J1DOvLV2w9Gyyn5cIc3niDCRNAaIgCwF
daucDOjqdy/GmzXfzz55W82dN5SZTPF6ppJafZw1nhy5iKTE1DoK8c0CgYEAyZHI
wQUGw5huxihZ7/v4KqYgsKQ3FVi6tCfnvFUGV+6pH+iJEmY386ilP1tdLBizMHKM
kHoP12CyOCfpp2XaMHAWShVXjQvedeWUJa9eWbUnbP5XZ7TpYAjiwTRPqJx4QS2/
WUKRb3w35A+FhY1Ht/fGnjutUm6OfGIAkpw93OkCgYEA41cki+/FS7wMLYTSqNMk
1MyX7iF6wbXPiIZWmPONEu9iaf6vP/pM9phSlhm0QLVbTuLuVpATtVL2BBaQywB8
l5Wgjie6xIdeWjkmh8/WsbrXVEiN7GHhJRqo7nyBjUWszDlD1hQel76CgQpBTGj3
IoLm7X83OvcfBtd+cgPFpHkCgYEAl7/8Tmx1Ui3hP6fDRewBQkJ9m96VZam+LcFZ
Mi0ksHCJvO74uvRfrT3K4m7rLzaNOK0Ua/SpFnHC2ooZ2x/P6uWHslBs8E/+M+4Z
4WEsfAbo3qKAtR+7DsTByciTLBJYamGBjDaUfUUcYsLYt9nMI5ETY67z5no7JSM2
4SllXXkCgYBHYPiZgBLhNB7jX3ayCPxb+79X4ZdjoBvN6kj2xjrwTatcrSeOZJ4u
P4g5P33yWtSqSN652XJPKd8Rl8WL39GIfRM/XV9FB+2mo4hmMEU9JBKxt8/E4nrM
5IOqkodYB1NmN9h32VOBg/ADKSXIIU3WuwXwemPgJpBSl2mHN/eJZg==
-----END RSA PRIVATE KEY-----
)KEY";