#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>
#include<iostream>

int main(int argc , char** argv ){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile("test_pcd.pcd",*cloud) == -1){
        PCL_ERROR("Could not read file .");
        return (-1);
    }
    // do processing with file
    std::cout<<"Loaded"
             << (cloud->width * cloud->height)
             << " data points from test_pcd.pcd with following fields"
             <<std::endl;
    for(size_t i=0; i< cloud->points.size(); i++){
        std::cout << "    " << cloud->points[i].x
              << " "    << cloud->points[i].y
              << " "    << cloud->points[i].z << std::endl;
    }         
    return(0);
}