FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl

RUN openssl req -x509 -newkey rsa:4096 -nodes -sha256 \
    -keyout /etc/ssl/private/localhost.key \
    -out /etc/ssl/certs/localhost.crt \
    -days 365 -subj "/C=KR/ST=SEOUL/L=SEOUL/O=42SEOUL/OU=gun/CN=localhost"
RUN chmod 600 /etc/ssl/*

COPY conf/default /etc/nginx/sites-available/

CMD ["nginx", "-g", "daemon off;"]