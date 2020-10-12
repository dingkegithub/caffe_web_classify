This is a action that caffe cpp web classify.

## required
 
boost, glog, caffe[must install caffe, see [http://caffe.berkeleyvision.org/install_apt.html](http://caffe.berkeleyvision.org/install_apt.html)]

## build

```
$: cd caffe_web_classify
$: mkdir build
$: cmake ..
$: make
```

## usage

#### configure setting

```
{
  "env": {
    "process_num": 1,   # it's not used
    "listen_port": 8080 # web listen port
  },

  "log": {
    "level": 1,    # glog level, 0: debug, 1: info
    "size": 20,    # glog size
    "dir": "", 
    "name": "log"  # glog name
  },

  "acr": {
    "model": "",     # caffe trained file
    "mean": "",      # caffe mean file
    "deploy": "",    # caffe deploy file, like deploy.prototxt
    "word": "",      # your model ouput word, like synset_word.txt
    "gpu_enable": false, # gpu: true;  cpu: false
    "gpu_number": 0      # which gpu that you will using.
  }
}
```

#### start server

```
$: (./caffe_web_classify --conf src/setting/setting.json &)
```
