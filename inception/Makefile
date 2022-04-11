all:
	cd srcs && docker-compose up -d
down:
	cd srcs && docker-compose down
	docker image prune -a -f
	docker volume prune
