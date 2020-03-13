tar xvzf web.tar.gz

chmod +x apply_autoindexing.sh

chmod +x mkcert
./mkcert -install
./mkcert localhost

rm -rf /etc/nginx/sites-enabled/default
cp configs/nginx.conf /etc/nginx/sites-enabled/

service mysql start

echo "CREATE DATABASE wordpress;" | mysql -u root 
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'mdp';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

/etc/init.d/php7.3-fpm start
service nginx start

tail -f /var/log/nginx/access.log /var/log/nginx/error.log
