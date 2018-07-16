/* Copyright (C) 2016-2018 University of California, Irvine
 * 
 * Authors:
 * Seyed Mohammadjavad Seyed Talebi <mjavad@uci.edu>
 * Ardalan Amiri Sani <arrdalan@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/Charm/prints.h>
#include <linux/Charm/charm_irq.h>


extern int send_irq_charm(uint64_t irq);
extern int charm_began;


static irqreturn_t charm_irq_handler(int irq_num, void *data)
{
        if(charm_began){
                send_irq_charm(irq_num);
        }
        return IRQ_HANDLED;
}

void register_irq_handlers (void)
{
	int rc;
	struct platform_device * pdev_irq;
	struct device * dev_irq;
	struct resource * cci_irq;	
	struct resource * csiphy_irq1;
	struct resource * csiphy_irq2;
	struct resource * csiphy_irq3;

	struct resource * csid_irq1;
	struct resource * csid_irq2;
	struct resource * csid_irq3;
	struct resource * csid_irq4;


	struct resource * vfe_irq; 
	struct resource * vfe_irq1; 
	struct resource * cpp_irq; 
	struct resource * ispif_irq;


	struct resource * slim_irq; 
	struct resource * wcdxxx_irq; 


///irq for cci
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda0c000.qcom,cci" );
	pdev_irq = to_platform_device(dev_irq);
	rc = of_platform_populate(dev_irq->of_node, NULL, NULL, dev_irq);
	if (rc)
		PRINTKL("%s: failed to add child nodes, rc=%d\n", __func__, rc);
	cci_irq = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "cci");	
	rc = request_irq(cci_irq->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "cci", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("cci irq num %d",(int)cci_irq->start);
	}		
	
////irq for csiphy1
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda0ac00.qcom,csiphy" );
	pdev_irq = to_platform_device(dev_irq);
	csiphy_irq1 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csiphy");	
	rc = request_irq(csiphy_irq1->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csiphy", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csiphy irq1 num %d",(int)csiphy_irq1->start);	
	}


////irq for csiphy2
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda0b000.qcom,csiphy" );
	pdev_irq = to_platform_device(dev_irq);
	csiphy_irq2 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csiphy");	
	rc = request_irq(csiphy_irq2->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csiphy", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csiphy irq2 num %d",(int)csiphy_irq2->start);	
	}


////irq for csiphy3
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda0b400.qcom,csiphy" );
	pdev_irq = to_platform_device(dev_irq);
	csiphy_irq3 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csiphy");	
	rc = request_irq(csiphy_irq3->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csiphy", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csiphy irq3 num %d",(int)csiphy_irq3->start);	
	}


////irq for csid1
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda08000.qcom,csid" );
	pdev_irq = to_platform_device(dev_irq);
	csid_irq1 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csid");	
	rc = request_irq(csid_irq1->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csid", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csid irq1 num %d",(int)csid_irq1->start);	
	}

////irq for csid2
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda08400.qcom,csid" );
	pdev_irq = to_platform_device(dev_irq);
	csid_irq2 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csid");	
	rc = request_irq(csid_irq2->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csid", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csid irq2 num %d",(int)csid_irq2->start);	
	}


////irq for csid3
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda08800.qcom,csid" );
	pdev_irq = to_platform_device(dev_irq);
	csid_irq3 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csid");	
	rc = request_irq(csid_irq3->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csid", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csid irq3 num %d",(int)csid_irq3->start);	
	}

////irq for csid4
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda08c00.qcom,csid" );
	pdev_irq = to_platform_device(dev_irq);
	csid_irq4 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "csid");	
	rc = request_irq(csid_irq4->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "csid", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("csid irq3 num %d",(int)csid_irq4->start);	
	}


////irq for ispif
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda0a000.qcom,ispif" );
	pdev_irq = to_platform_device(dev_irq);
	ispif_irq = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "ispif");	
	rc = request_irq(ispif_irq->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "ispif", dev_irq);
	
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("ispif irq num %d",(int)ispif_irq->start);	
	}
////irq for vfe0
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda10000.qcom,vfe" );
	pdev_irq = to_platform_device(dev_irq);
	vfe_irq = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "vfe");	
	rc = request_irq(vfe_irq->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "vfe", dev_irq);
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("vfe irq num %d",(int)vfe_irq->start);	
	}



////irq for vfe1
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda14000.qcom,vfe" );
	pdev_irq = to_platform_device(dev_irq);
	vfe_irq1 = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "vfe");	
	rc = request_irq(vfe_irq1->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "vfe", dev_irq);
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("vfe irq1 num %d",(int)vfe_irq1->start);	
	}

////irq for cpp
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fda04000.qcom,cpp" );
	pdev_irq = to_platform_device(dev_irq);
	cpp_irq = platform_get_resource_byname(pdev_irq,IORESOURCE_IRQ, "cpp");	
	rc = request_irq(cpp_irq->start, charm_irq_handler,
		IRQF_TRIGGER_RISING, "cpp", dev_irq);
	if (rc < 0) {
		PRINTKL("%s: irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("cpp irq num %d",(int)cpp_irq->start);	
	}


////irq for slim
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"fe12f000.slim" );
	pdev_irq = to_platform_device(dev_irq);
	slim_irq = platform_get_resource_byname(pdev_irq, IORESOURCE_IRQ,"slimbus_irq");

	rc = request_irq(slim_irq->start,charm_irq_handler,IRQF_TRIGGER_RISING,"ngd_slim_irq", dev_irq);

	if (rc < 0) {
		PRINTKL("%s: slim ngd irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("slim ngd irq num %d",(int)slim_irq->start);	
	}


////irq for wcdxxx
	dev_irq = bus_find_device_by_name(&platform_bus_type,NULL,"wcd9xxx-irq.34" );
	pdev_irq = to_platform_device(dev_irq);
	wcdxxx_irq = platform_get_resource_byname(pdev_irq, IORESOURCE_IRQ,"cdc-int");

	rc = request_irq(wcdxxx_irq->start,charm_irq_handler,IRQF_TRIGGER_RISING,"wcd9xxx", dev_irq);

	if (rc < 0) {
		PRINTKL("%s: wcdxxxx irq request fail\n", __func__);
		BUG();
	}else{
		PRINTKL("wcdxxxx irq num %d",(int)wcdxxx_irq->start);	
	}

}
