FROM debian:buster

RUN apt-get -y update \
 		 && apt-get -y install \
 		 php nginx \
		 mariadb-server \
 		 php-cli \
 		 php-mysql \
 		 php-curl \
  		 php-gd \
 		 php-intl \
 		 libnss3-tools \
 		 php-fpm \
 		 php-mbstring \
		 && apt-get clean -y

WORKDIR ft_server

COPY srcs .

EXPOSE 80 443

ENTRYPOINT ["bash", "entrypoint.sh"]
