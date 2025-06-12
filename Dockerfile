FROM ubuntu:22.04 as builder

RUN apt-get update && \
    apt-get -y install git cmake build-essential wget file qtbase6-dev libqt6svg6-dev \
                       libqt6websockets6-dev libqt6opengl6-dev libqt6x11extras6-dev \
                       libprotoc-dev libzmq3-dev liblz4-dev libzstd-dev libmosquittopp-dev

RUN mkdir -p /opt/plotjuggler
COPY . /opt/plotjuggler
RUN mkdir /opt/plotjuggler/build
WORKDIR /opt/plotjuggler/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
RUN make -j `nproc`
RUN make install DESTDIR=AppDir
RUN /opt/plotjuggler/appimage/AppImage.sh

FROM scratch AS exporter
COPY --from=builder /opt/plotjuggler/build/PlotJuggler-x86_64.AppImage /
