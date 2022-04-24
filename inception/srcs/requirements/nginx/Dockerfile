# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 13:59:15 by dahpark           #+#    #+#              #
#    Updated: 2022/04/23 13:59:17 by dahpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get install -y nginx \
openssl

RUN openssl req -x509 -newkey rsa:4096 -nodes -sha256 \
    -keyout /etc/ssl/private/dahpark.key \
    -out /etc/ssl/certs/dahpark.crt \
    -days 365 -subj "/C=KR/ST=SEOUL/L=SEOUL/O=42SEOUL/OU=gun/CN=dahpark"
RUN chmod 600 /etc/ssl/*

COPY conf/default /etc/nginx/sites-available/

CMD ["nginx", "-g", "daemon off;"]
